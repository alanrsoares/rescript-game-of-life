open Util;

module Wrapper = [%stiled.div
  {|
    display: flex;
    border: 1px solid red;
  |}
];

[@react.component]
let make = () => <Wrapper> "grid"->str </Wrapper>;