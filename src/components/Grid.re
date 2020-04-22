open Util;

module Wrapper = [%stiled.div
  {|
    display: flex;
    border: .2em solid black;
    border-radius: .5em;
  |}
];

[@react.component]
let make = (~data: Game.grid, ~onToggle) => {
  open Belt.Array;

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
        {row->mapWithIndex(renderTile(y)) |> arr}
      </div>
    );

  <Wrapper> {data->mapWithIndex(renderRow) |> arr} </Wrapper>;
};