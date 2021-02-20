open CoreComponents

module Wrapper = %styled.div(`
  display: flex;
  justify-content: center;
  align-items: center;
  padding: 2rem 0;
`)

@react.component
let make = (~isPlaying, ~onReset, ~onRandom, ~onTick, ~onToggleAutoplay) =>
  <Wrapper>
    <div role="group">
      <Button label="Reset grid" background="#ee5f5b" onClick=onReset>
        <Icon name="undo" />
      </Button>
      <Button label="Random grid" background="#62c462" onClick=onRandom>
        <Icon name="random" />
      </Button>
      <Button label="Next state" background="#7A8288" disabled=isPlaying onClick=onTick>
        <Icon name="forward" />
      </Button>
      <ToggleButton label="Toggle autpplay" isToggled=isPlaying onClick=onToggleAutoplay />
    </div>
  </Wrapper>
