open Model

open CoreComponents

module R = React

@react.component
let make = () => {
  let (state, dispatch) = R.useReducer(Reducers.root, initialState)
  let handleToggleTile = R.useCallback0((y, x) => dispatch(Toggle((y, x))))
  let handleReset = R.useCallback0(_ => dispatch(Reset))
  let handleRandom = R.useCallback0(_ => dispatch(Random))
  let handleTick = R.useCallback0(_ => dispatch(Tick))
  let handleToggleAutoPlay = R.useCallback2(_ => {
    let rec play = () => {
      state.animationFrameId := Util.requestAnimationFrame(play)
      dispatch(Tick)
    }
    if state.isPlaying {
      Util.cancelAnimationFrame(state.animationFrameId.contents)
      dispatch(Stop)
    } else {
      play()
      dispatch(Start)
    }
  }, (state.animationFrameId, state.isPlaying))

  let label = state.isPlaying
    ? "avg update rate: " ++ (state.frameRate->string_of_int ++ " fps")
    : ""

  <Root>
    <Content>
      <AppBar> {"Conway's Game of Life"->R.string} </AppBar>
      <Controls
        isPlaying=state.isPlaying
        onReset=handleReset
        onRandom=handleRandom
        onTick=handleTick
        onToggleAutoplay=handleToggleAutoPlay
      />
      <Grid data=state.grid onToggle=handleToggleTile />
      <div> {label->R.string} </div>
    </Content>
  </Root>
}
