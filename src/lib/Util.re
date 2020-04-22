[@bs.val]
external requestAnimationFrame: (unit => unit) => int =
  "requestAnimationFrame";

[@bs.val] external cancelAnimationFrame: int => unit = "cancelAnimationFrame";

let str = ReasonReact.string;
let arr = ReasonReact.array;

let avgFrameRate = (ticks, startedAt) =>
  Js.Math.ceil(
    ticks->float_of_int
    /. ((Js.Date.now() -. startedAt) /. float_of_int(1000)),
  );

let makeStyle = ReactDOMRe.Style.make;