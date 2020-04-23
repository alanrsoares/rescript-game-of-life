module Wrapper = [%styled.div
  (~background, ~shadow) => {j|
    width: .9rem;
    height: .9rem;
    margin: 1px;
    background: $background;
    border-radius: 50%;
    transition-property: background;
    transition-duration: .1s;
    transition-timing-function: ease-in-out;
    cursor: pointer;
    box-shadow: $shadow;
  |j}
];

[@react.component]
let make = (~isAlive, ~onToggle, ~y, ~x) => {
  let aliveColor = Util.Colors.rainbowHSL(y, x);
  let deadColor = "#272B30";
  let background = isAlive ? aliveColor : deadColor;

  let handleMouseEvent =
    React.useCallback0((callback, e) =>
      if (ReactEvent.Mouse.nativeEvent(e)##which === 1) {
        callback();
      }
    );

  <Wrapper
    onMouseOver={handleMouseEvent(onToggle)}
    onMouseDown={handleMouseEvent(onToggle)}
    background
    shadow={isAlive ? {j|0 0 2px 1px $aliveColor|j} : ""}
  />;
};