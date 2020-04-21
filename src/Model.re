type state = {
  grid: Game.grid,
  isPlaying: bool,
  animationFrameId: ref(int),
  score: ref(int),
  startedAt: option(float),
  ticks: int,
  frameRate: int,
};

type action =
  | Random
  | Reset
  | Start
  | Stop
  | Tick
  | Toggle(Game.position);

let make_seed = () => Js.Date.now()->int_of_float;

let boardSize = 30;

let initialState = {
  grid: Game.make_random_grid(boardSize, make_seed()),
  isPlaying: false,
  animationFrameId: ref(0),
  score: ref(0),
  startedAt: None,
  ticks: 0,
  frameRate: 0,
};

module Reducers = {
  let grid = (self, action, state): Game.grid =>
    switch (action) {
    | Random => Game.make_random_grid(boardSize, make_seed())
    | Reset => Game.make_blank_grid(30)
    | Tick => Game.next_generation(state.score, self)
    | Toggle(position) => self->Game.toggle_tile(position)
    | _ => self
    };

  let score = (self, action, _state) =>
    switch (action) {
    | Random => ref(0)
    | Reset => ref(0)
    | _ => self
    };

  let isPlaying = (self, action, _state) =>
    switch (action) {
    | Start => true
    | Stop => false
    | _ => self
    };

  let startedAt = (self, action, _state) =>
    switch (action) {
    | Start => Some(Js.Date.now())
    | Stop => None
    | _ => self
    };

  let ticks = (self, action, state) =>
    switch (action, state.isPlaying) {
    | (Reset, _) => 0
    | (Stop, _) => 0
    | (Tick, true) => self + 1
    | _ => self
    };

  let frameRate = (self, action, state) =>
    switch (action, state.startedAt) {
    | (Stop, _) => 0
    | (Tick, Some(startedAt)) => Util.avg_frame_rate(state.ticks, startedAt)
    | _ => self
    };

  let root = (state, action) => {
    animationFrameId: state.animationFrameId,
    grid: grid(state.grid, action, state),
    isPlaying: isPlaying(state.isPlaying, action, state),
    score: score(state.score, action, state),
    startedAt: startedAt(state.startedAt, action, state),
    ticks: ticks(state.ticks, action, state),
    frameRate: frameRate(state.frameRate, action, state),
  };
};