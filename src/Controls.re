open Util;

module Wrapper = [%styled.div
  {|
    display: flex;
    justify-content: center;
    align-items: center;
    padding: 2rem 0;
  |}
];

module Button = [%styled.button
  (~background) => {j|
    font-size: .9rem;
    padding: .5rem .8rem;
    background-color: $background;
    min-width: 5rem;
    color: white;
    border-radius: .3rem;
    margin: 0 .1rem;
    border-width: 0;
    user-select: none;
    outline: 0rem none white;
    font-weight: 700;
    cursor: pointer;
  |j}
];

module ToggleButton = {
  [@react.component]
  let make = (~isToggled, ~onClick, ~disabled=false) =>
    <Button background="gray" onClick disabled>
      (isToggled ? "PAUSE" : "PLAY")->str
    </Button>;
};

[@react.component]
let make = (~isPlaying, ~onReset, ~onRandom, ~onTick, ~onToggleAutoplay) =>
  <Wrapper>
    <div role="group">
      <Button background="#ee5f5b" onClick=onReset> "RESET"->str </Button>
      <Button background="#62c462" onClick=onRandom> "RANDOMIZE"->str </Button>
      <Button background="#7A8288" disabled=isPlaying onClick=onTick>
        "NEXT"->str
      </Button>
      <ToggleButton isToggled=isPlaying onClick=onToggleAutoplay />
    </div>
  </Wrapper>;