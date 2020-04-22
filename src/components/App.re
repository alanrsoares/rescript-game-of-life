open Model;
open Util;
open CoreComponents;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(Reducers.root, initialState);

  let handleToggleTile =
    React.useCallback0((y, x) => dispatch(Toggle((y, x))));
  let handleReset = React.useCallback0(_ => dispatch(Reset));
  let handleRandom = React.useCallback0(_ => dispatch(Random));
  let handleTick = React.useCallback0(_ => dispatch(Tick));

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
      <AppBar> "Conway's Game of Life"->str </AppBar>
      <Controls
        isPlaying={state.isPlaying}
        onReset=handleReset
        onRandom=handleRandom
        onTick=handleTick
        onToggleAutoplay=handleToggleAutoPlay
      />
      <Grid data={state.grid} onToggle=handleToggleTile />
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