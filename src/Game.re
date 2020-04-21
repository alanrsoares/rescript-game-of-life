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
  let (y, x) = position->safePosition(Array.length(grid));
  grid[y][x];
};

let getNeighbours = ((y, x): position, grid): list(cellState) =>
  [
    (y - 1, x - 1),
    (y - 1, x),
    (y - 1, x + 1),
    (y, x - 1),
    (y, x + 1),
    (y + 1, x - 1),
    (y + 1, x),
    (y + 1, x + 1),
  ]
  |> List.map(grid->getTile);

let countLivingNeighbours = (grid, position): int =>
  List.(
    grid
    |> getNeighbours(position)
    |> filter(c => c === Alive)  /* only live cells */
    |> length
  );

let nextState = (score: ref(int), position, cellState: cellState, grid) => {
  let neighbours = grid->countLivingNeighbours(position);

  switch (cellState, neighbours) {
  | (Alive, 2 | 3) => Alive
  | (Dead, 3) =>
    /* sneaky ref update */
    score := score^ + 1;
    Alive;
  | _ => Dead
  };
};

let nextGeneration = score => mapGrid(nextState(score));

let toggleTile = (grid, position) => {
  let grid' = grid->Belt.Array.(map(copy));
  let (y, x) = position->safePosition(grid->Belt.Array.length);
  let tile = grid'[y][x];

  grid'[y][x] = (
    switch (tile) {
    | Alive => Dead
    | _ => Alive
    }
  );

  grid';
};