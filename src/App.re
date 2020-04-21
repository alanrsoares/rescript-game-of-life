open Util;

module Wrapper = [%styled.div
  {|
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100vh;
    width: 100vw;
  |}
];

module Tile = [%styled.div
  {|
    background-color: #ccc;
    border: 1px solid red;
    padding: 1vh;
    border-radius: .4em;
  |}
];

[@react.component]
let make = (~seed) =>
  <Wrapper>
    <Tile>
      <button> ("Seed: " ++ seed->string_of_int ++ "!")->str </button>
    </Tile>
  </Wrapper>;