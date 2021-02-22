module R = React
module A = Belt.Array

module Wrapper = %stiled.div(`
  display: flex;
  border: .25rem solid #222;
  border-radius: .75rem;
  padding: .125rem;
`)

@react.component
let make = (~data: Game.grid, ~onToggle) => {
  let renderTile = R.useCallback0((y, x, cellState: Game.cellState) => {
    let key = j`$x-$y`

    <Tile isAlive={cellState === Game.Alive} key onToggle={_ => onToggle(y, x)} y x />
  })

  let renderRow = R.useCallback0((y, row) =>
    <div key={y->string_of_int}> {row->A.mapWithIndex(renderTile(y))->R.array} </div>
  )

  <Wrapper> {data->A.mapWithIndex(renderRow)->R.array} </Wrapper>
}
