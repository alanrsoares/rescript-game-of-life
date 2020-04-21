open Model;
open Util;
open CoreComponents;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(Reducers.root, initialState);

  let handleToggle = React.useCallback0((y, x) => dispatch(Toggle((y, x))));
  let handleToggleAutoPlay =
    React.useCallback2(
      _ => {
        let rec play = () => {
          state.animationFrameId := requestAnimationFrame(play);
          dispatch(Tick);
        };
        if (state.isPlaying) {
          cancelAnimationFrame(state.animationFrameId^);
          dispatch(Stop);
        } else {
          play();
          dispatch(Start);
        };
      },
      (state.animationFrameId, state.isPlaying),
    );

  <Root>
    <Content>
      <AppBar> "Conway's Game of Life"->Util.str </AppBar>
      <Controls
        isPlaying={state.isPlaying}
        onReset={_ => dispatch(Reset)}
        onRandom={_ => dispatch(Random)}
        onTick={_ => dispatch(Tick)}
        onToggleAutoplay=handleToggleAutoPlay
      />
      <Grid data={state.grid} onToggle=handleToggle />
      <div>
        (
          state.isPlaying ?
            "avg update rate: " ++ state.frameRate->string_of_int ++ " fps" :
            ""
        )
        ->str
      </div>
    </Content>
  </Root>;
};