type state = {
  grid: Game.grid,
  isPlaying: bool,
  animationFrameId: ref<int>,
  startedAt: option<float>,
  ticks: int,
  frameRate: int,
}

type action =
  | Random
  | Reset
  | Start
  | Stop
  | Tick
  | Toggle(Game.point)

let makeSeed = () => Js.Date.now()->int_of_float

let initialState = {
  grid: Game.makeRandomGrid(Config.boardSize, makeSeed()),
  isPlaying: false,
  animationFrameId: ref(0),
  startedAt: None,
  ticks: 0,
  frameRate: 0,
}

module Reducers = {
  let grid = (self, action, _state): Game.grid =>
    switch action {
    | Random => Game.makeRandomGrid(Config.boardSize, makeSeed())
    | Reset => Game.makeBlankGrid(Config.boardSize)
    | Tick => Game.nextGeneration(self)
    | Toggle(position) => self->Game.toggleTile(position)
    | _ => self
    }

  let isPlaying = (self, action, _state) =>
    switch action {
    | Start => true
    | Stop => false
    | _ => self
    }

  let startedAt = (self, action, _state) =>
    switch action {
    | Start => Some(Js.Date.now())
    | Stop => None
    | _ => self
    }

  let ticks = (self, action, state) =>
    switch (action, state.isPlaying) {
    | (Reset, _) => 0
    | (Stop, _) => 0
    | (Tick, true) => self + 1
    | _ => self
    }

  let frameRate = (self, action, state) =>
    switch (action, state.startedAt) {
    | (Stop, _) => 0
    | (Tick, Some(startedAt)) => Util.avgFrameRate(state.ticks, startedAt)
    | _ => self
    }

  let root = (state, action) => {
    animationFrameId: state.animationFrameId,
    grid: grid(state.grid, action, state),
    isPlaying: isPlaying(state.isPlaying, action, state),
    startedAt: startedAt(state.startedAt, action, state),
    ticks: ticks(state.ticks, action, state),
    frameRate: frameRate(state.frameRate, action, state),
  }
}
