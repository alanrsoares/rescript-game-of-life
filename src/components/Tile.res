module Wrapper = %styled.div(
  (~background, ~shadow, ~tileSize) =>
    `
    width: $(tileSize);
    height: $(tileSize);
    background: $(background);
    border-radius: 50%;
    margin: 2px 1px;
    padding: 0;
    transition-property: "all";
    transition-duration: .1s;
    transition-timing-function: ease-in-out;
    cursor: pointer;
    box-shadow: $(shadow);
  `
)

@react.component
let make = (~isAlive, ~onToggle, ~y, ~x) => {
  let aliveColor = Util.Colors.rainbowHSL(y, x)
  let deadColor = "#272B30"
  let (background, shadow) = isAlive ? (aliveColor, j`0 0 0 0 $aliveColor`) : (deadColor, "")

  let handleMouseEvent = React.useCallback0((callback, e) =>
    if ReactEvent.Mouse.nativeEvent(e)["which"] === 1 {
      callback()
    }
  )

  <Wrapper
    background
    shadow
    onMouseOver={handleMouseEvent(onToggle)}
    onMouseDown={handleMouseEvent(onToggle)}
    tileSize=Config.tileSize
  />
}
