let str = ReasonReact.string;

let avg_frame_rate = (ticks, startedAt) =>
  Js.Math.ceil(
    ticks->float_of_int
    /. ((Js.Date.now() -. startedAt) /. float_of_int(1000)),
  );