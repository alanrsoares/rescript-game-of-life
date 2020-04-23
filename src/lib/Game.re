type cellState =
  | Dead
  | Alive;

type grid = array(array(cellState));

type position = (int, int);

let safeIndex = (len, i) => i < 0 ? len - 1 : i === len ? 0 : i;

let safePosition = ((y, x): position, len): position => (
  safeIndex(len, y),
  safeIndex(len, x),
);

let mapGrid = (fn: (position, cellState, grid) => cellState, grid): grid =>
  Belt.Array.(
    mapWithIndex(grid, (y, row) =>
      row->mapWithIndex((x, tile) => fn((y, x), tile, grid))
    )
  );

let makeBlankGrid = (size': int): grid =>
  Belt.Array.(make(size', make(size', Dead)));

let makeRandomGrid = (size: int, seed: int): grid => {
  Random.init(seed);
  size
  |> makeBlankGrid
  |> mapGrid((_, _, _) => Random.int(10) > 7 ? Alive : Dead);
};

let getTile = (grid, position): cellState => {
  let (y, x) = position->safePosition(grid->Belt.Array.length);

  grid[y][x];
};

let offset = [(-1), 0, 1];

let getNeighbours = (grid, (y, x): position): list(cellState) =>
  Belt.List.(
    offset
    ->map(y' => offset->map(x' => (y + y', x + x')))
    ->flatten
    ->keep(p => p != (y, x))
    ->map(grid->getTile)
  );

let countLivingNeighbours = (grid, position): int =>
  Belt.List.(grid->getNeighbours(position)->keep(c => c == Alive)->length);

let nextState = (position, cellState, grid) => {
  let neighbours = grid->countLivingNeighbours(position);

  switch (cellState, neighbours) {
  | (Alive, 2 | 3) => Alive
  | (Dead, 3) => Alive
  | _ => Dead
  };
};

let nextGeneration = mapGrid(nextState);

let toggleTile = (grid, position) => {
  open Belt.Array;

  let grid' = grid->map(copy);
  let (y, x) = position->safePosition(grid->length);
  let tile = grid'[y][x];

  grid'[y][x] = (
    switch (tile) {
    | Alive => Dead
    | _ => Alive
    }
  );

  grid';
};