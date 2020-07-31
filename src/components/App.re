open Model;
open Util;
open CoreComponents;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(Reducers.root, initialState);

  let handleToggleTile =
    React.useCallback1((y, x) => dispatch(Toggle((y, x))), [|dispatch|]);
  let handleReset = React.useCallback1(_ => dispatch(Reset), [|dispatch|]);
  let handleRandom =
    React.useCallback1(_ => dispatch(Random), [|dispatch|]);
  let handleTick = React.useCallback1(_ => dispatch(Tick), [|dispatch|]);
  let handleToggleAutoPlay =
    React.useCallback3(
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
      (state.animationFrameId, state.isPlaying, dispatch),
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
          state.isPlaying
            ? "avg update rate: " ++ state.frameRate->string_of_int ++ " fps"
            : ""
        )
        ->str
      </div>
    </Content>
  </Root>;
};
