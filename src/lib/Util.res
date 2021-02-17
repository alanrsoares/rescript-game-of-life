@val
external requestAnimationFrame: (unit => unit) => int = "requestAnimationFrame"

@val
external cancelAnimationFrame: int => unit = "cancelAnimationFrame"

let avgFrameRate = (ticks, startedAt) =>
  Js.Math.ceil(ticks->float_of_int /. ((Js.Date.now() -. startedAt) /. float_of_int(1000)))

module Colors = {
  @module("polished")
  external opacify: (float, string) => string = "opacify"

  let sqrSize = Config.boardSize * Config.boardSize

  let sumOfSquares = (sqrSize * 2)->float_of_int
  let diagonalLength = Js.Math.sqrt(sumOfSquares)
  let hueIncrement = 360. /. diagonalLength

  let colorCache = Belt.HashMap.String.make(~hintSize=sqrSize)

  let rainbowHSL = (y, x) => {
    let cacheKey = j`$y-$x`

    let (color, cached) = switch colorCache->Belt.HashMap.String.get(cacheKey) {
    | Some(found) => (found, true)
    | None =>
      let sumOfPoints = (y * y + x * x)->float_of_int
      let raw = Js.Math.sqrt(sumOfPoints) *. hueIncrement
      let h = raw->Js.Math.floor
      let color = j`hsl($h, 100%, 60%)`

      (color, false)
    }

    if !cached {
      colorCache->Belt.HashMap.String.set(cacheKey, color)
    }

    color
  }
}
