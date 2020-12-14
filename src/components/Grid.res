open Util

module Wrapper = %stiled.div(`
    display: flex;
    border: .25rem solid #222;
    border-radius: .75rem;
    padding: .125rem;
  `)

module A = Belt.Array

@react.component
let make = (~data: Game.grid, ~onToggle) => {
  let renderTile = React.useCallback0((y, x, cellState: Game.cellState) =>
    <Tile isAlive={cellState === Game.Alive} key=j`$x-$y` onToggle={_ => onToggle(y, x)} y x />
  )

  let renderRow = React.useCallback0((y, row) =>
    <div key={y->string_of_int}> {row->A.mapWithIndex(renderTile(y))->arr} </div>
  )

  <Wrapper> {data->A.mapWithIndex(renderRow)->arr} </Wrapper>
}
