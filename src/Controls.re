open Util;

module Wrapper = [%styled.div
  {|
    display: flex;
    border: 1px solid red;
  |}
];

[@react.component]
let make = () => <Wrapper> "controls"->str </Wrapper>;