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

module Colors = {
  let sqrSize = Config.boardSize * Config.boardSize;

  let sumOfSquares = (sqrSize * 2)->float_of_int;
  let diagonalLength = Js.Math.sqrt(sumOfSquares);
  let hueIncrement = 360. /. diagonalLength;

  type memo = Hashtbl.t((int, int), string);

  let cache = Hashtbl.create(~random=true, sqrSize);

  let rainbowHSL = (y, x) => {
    let (color, cached) =
      switch (Hashtbl.find(cache, (y, x))) {
      | f => (f, true)
      | exception Not_found =>
        let sumOfPoints = (y * y + x * x)->float_of_int;
        let h = Js.Math.floor(Js.Math.sqrt(sumOfPoints) *. hueIncrement);
        ({j|hsl($h, 100%, 60%)|j}, false);
      };

    if (!cached) {
      Hashtbl.add(cache, (y, x), color);
    };

    color;
  };
};