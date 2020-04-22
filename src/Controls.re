open CoreComponents;

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
  let make = (~isToggled, ~onClick, ~label, ~disabled=false) => {
    let icon = isToggled ? "pause-circle" : "play-circle";
    let background = isToggled ? "#666" : "#7A8288";

    <Button label background onClick disabled> <Icon name=icon /> </Button>;
  };
};

[@react.component]
let make = (~isPlaying, ~onReset, ~onRandom, ~onTick, ~onToggleAutoplay) =>
  <Wrapper>
    <div role="group">
      <Button label="Reset grid" background="#ee5f5b" onClick=onReset>
        <Icon name="undo" />
      </Button>
      <Button label="Random grid" background="#62c462" onClick=onRandom>
        <Icon name="random" />
      </Button>
      <Button
        label="Next state"
        background="#7A8288"
        disabled=isPlaying
        onClick=onTick>
        <Icon name="forward" />
      </Button>
      <ToggleButton
        label="Toggle autpplay"
        isToggled=isPlaying
        onClick=onToggleAutoplay
      />
    </div>
  </Wrapper>;