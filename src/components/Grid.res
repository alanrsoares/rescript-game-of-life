open Util

module Wrapper = %stiled.div(
  `
    display: flex;
    border: .25rem solid #222;
    border-radius: .75rem;
    padding: .125rem;
  `
)

@react.component
let make = (~data: Game.grid, ~onToggle) => {
  open Belt.Array

  let renderTile = React.useCallback1(
    (y, x, cellState: Game.cellState) =>
      <Tile isAlive={cellState === Game.Alive} key=j`$x-$y` onToggle={_ => onToggle(y, x)} y x />,
    [onToggle],
  )

  let renderRow = React.useCallback1(
    (y, row) => <div key={y->string_of_int}> {row->mapWithIndex(renderTile(y)) |> arr} </div>,
    [renderTile],
  )

  <Wrapper> {data->mapWithIndex(renderRow) |> arr} </Wrapper>
}
