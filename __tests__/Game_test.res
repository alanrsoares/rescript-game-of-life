open Jest

describe("Game", () => {
  open Expect

  let x = Game.Alive
  let o = Game.Dead

  describe("makeRandomGrid", () =>
    test("should create a grid with the correct length", () =>
      expect(Game.makeRandomGrid(3, 2)->Belt.Array.length) |> toBe(3)
    )
  )

  describe("getTile", () => test("should get the value of a tile given the positions", () => {
      let grid = [[o, o, o], [x, x, x], [o, o, o]]
      let tilePosition = (1, 1)

      expect(grid->Game.getTile(tilePosition)) |> toBe(Game.Alive)
    }))

  describe("countLivingNeighbours", () =>
    test("should get number of live neighbours of a given tile", () => {
      let grid = [[o, o, o], [x, x, x], [o, o, o]]
      let tilePosition = (0, 1)

      expect(grid->Game.countLivingNeighbours(tilePosition)) |> toBe(3)
    })
  )

  describe("toggleTile", () => {
    let grid = [[o, o, o], [x, x, x], [o, o, o]]
    let nextGrid = [[o, o, o], [x, o, x], [o, o, o]]
    let tilePosition = (1, 1)

    test("should toggle the middle cell", () =>
      expect(grid->Game.toggleTile(tilePosition)) |> toEqual(nextGrid)
    )

    test("should revert the middle cell to its original state", () =>
      expect(nextGrid->Game.toggleTile(tilePosition)) |> toEqual(grid)
    )
  })

  describe("nextGeneration", () => {
    describe("the cross pattern", () => {
      let grid = [
        [o, o, o, o, o],
        [o, o, o, o, o],
        [o, x, x, x, o],
        [o, o, o, o, o],
        [o, o, o, o, o],
      ]

      let nextGrid = [
        [o, o, o, o, o],
        [o, o, x, o, o],
        [o, o, x, o, o],
        [o, o, x, o, o],
        [o, o, o, o, o],
      ]

      test("should transform a horizontal to a vertical line", () =>
        expect(grid->Game.nextGeneration) |> toEqual(nextGrid)
      )

      test("should revert a vertical line to a horizontal one", () =>
        expect(nextGrid->Game.nextGeneration) |> toEqual(grid)
      )
    })

    describe("the glider pattern", () => {
      let grid = [
        [o, x, o, o, o],
        [o, o, x, o, o],
        [x, x, x, o, o],
        [o, o, o, o, o],
        [o, o, o, o, o],
      ]

      let nextGrid = [
        [o, o, o, o, o],
        [x, o, x, o, o],
        [o, x, x, o, o],
        [o, x, o, o, o],
        [o, o, o, o, o],
      ]

      test("should move a glider to the next step", () =>
        expect(grid->Game.nextGeneration) |> toEqual(nextGrid)
      )
    })
  })
})
