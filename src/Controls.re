open CoreComponents;

module Wrapper = [%styled.div
  {|
    display: flex;
    justify-content: center;
    align-items: center;
    padding: 2rem 0;
  |}
];

module Button = {
  [@react.component]
  let make = (~label, ~background, ~onClick, ~disabled=false, ~children) => {
    let className = [%css
      {j|
        font-size: .9rem;
        padding: .5rem .8rem;
        background-color: $background;
        width: 3rem;
        height: 3rem;
        color: white;
        border-radius: 50%;
        margin: 0 .5rem;
        border-width: 0;
        user-select: none;
        outline: 0rem none white;
        font-weight: 700;
        cursor: pointer;
      |j}
    ];

    <button ariaLabel=label className disabled onClick> children </button>;
  };
};

module ToggleButton = {
  [@react.component]
  let make = (~isToggled, ~onClick, ~label, ~disabled=false) => {
    let background = isToggled ? "#666" : "#7A8288";
    let name = isToggled ? "pause-circle" : "play-circle";

    <Button label background onClick disabled> <Icon name /> </Button>;
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