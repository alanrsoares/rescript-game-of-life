type cellState =
  | Dead
  | Alive

type grid = array<array<cellState>>

type point = (int, int)

module L = Belt.List
module A = Belt.Array

let safeIndex = x =>
  switch x {
  | (length, i) when i < 0 => length - 1
  | (length, i) when i === length => 0
  | (_, i) => i
  }

let safePoint = ((y, x): point, length: int): point => (
  (length, y)->safeIndex,
  (length, x)->safeIndex,
)

let mapGrid = (fn: (point, cellState, grid) => cellState, grid): grid => {
  A.mapWithIndex(grid, (y, row) => row->A.mapWithIndex((x, tile) => fn((y, x), tile, grid)))
}

let makeBlankGrid = (size': int): grid => {
  A.make(size', A.make(size', Dead))
}

let makeRandomGrid = (size: int, seed: int): grid => {
  Random.init(seed)
  size->makeBlankGrid |> mapGrid((_, _, _) => Random.int(10) > 7 ? Alive : Dead)
}

let getTile = (grid, point): cellState => {
  let (y, x) = point->safePoint(grid->A.length)

  grid[y][x]
}

let offset = list{-1, 0, 1}

let getNeighbours = (grid, (y, x): point): list<cellState> => {
  offset
  ->L.map(y' => offset->L.map(x' => (y + y', x + x')))
  ->L.flatten
  ->L.keep(p => p != (y, x))
  ->L.map(grid->getTile)
}

let countLivingNeighbours = (grid, point): int => {
  grid->getNeighbours(point)->L.keep(c => c == Alive)->L.length
}

let nextState = (point, cellState, grid) => {
  let neighbours = grid->countLivingNeighbours(point)

  switch (cellState, neighbours) {
  | (Alive, 2 | 3) => Alive
  | (Dead, 3) => Alive
  | _ => Dead
  }
}

let nextGeneration = mapGrid(nextState)

let toggleTile = (grid, point) => {
  let grid' = grid->A.map(A.copy)
  let (y, x) = point->safePoint(grid->A.length)
  let tile = grid'[y][x]

  grid'[y][x] = switch tile {
  | Alive => Dead
  | _ => Alive
  }

  grid'
}
