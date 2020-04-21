open CoreComponents;
open Util;

open Model;

module Wrapper = [%styled.div
  {|
    display: flex;
    height: 100vh;
    width: 100vw;
    flex-direction: column;
    background-color: #eaeaea;
  |}
];

[@react.component]
let make = () => {
  let (_state, _dispatch) = React.useReducer(Reducers.root, initialState);

  <Wrapper>
    <Content>
      <AppBar> "Game of Life"->str </AppBar>
      <Controls />
      <Grid />
      <Profiler />
    </Content>
  </Wrapper>;
};