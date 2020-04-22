open Util;

module Wrapper = [%stiled.div
  {|
    display: flex;
    border: .2em solid black;
    border-radius: .2em;
  |}
];

[@react.component]
let make = (~data: Game.grid, ~onToggle) => {
  let renderTile =
    React.useCallback1(
      (y, x, cellState: Game.cellState) =>
        <Tile
          isAlive={cellState === Game.Alive}
          key=x->string_of_int
          onToggle={_ => onToggle(y, x)}
        />,
      [|onToggle|],
    );

  let renderRow =
    React.useCallback0((y, row) =>
      <div key=y->string_of_int>
        {row->Belt.Array.mapWithIndex(renderTile(y)) |> arr}
      </div>
    );

  <Wrapper> {data->Belt.Array.mapWithIndex(renderRow) |> arr} </Wrapper>;
};