open Util;

module Wrapper = [%stiled.div
  {|
  display: flex;
  border: .2em solid black;
  border-radius: .2em;
|}
];

let renderTile = (onToggle, x: int, cellState: Game.cellState) =>
  <Tile
    isAlive={cellState === Game.Alive}
    key=x->string_of_int
    onToggle={_ => onToggle(x)}
  />;

let renderRow = (onToggle, y: int, row) =>
  <div key={string_of_int(y)}>
    {row->Belt.Array.mapWithIndex(renderTile(onToggle(y))) |> arr}
  </div>;

[@react.component]
let make = (~data: Game.grid, ~onToggle) =>
  <Wrapper>
    {data->Belt.Array.mapWithIndex(renderRow(onToggle)) |> arr}
  </Wrapper>;