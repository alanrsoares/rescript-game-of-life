let handleMouseEvent = (callback, e) =>
  if (ReactEvent.Mouse.nativeEvent(e)##which === 1) {
    callback();
  };

module Wrapper = [%styled.div
  (~background: string) => {j|
    width: .9rem;
    height: 1rem;
    margin: .05rem;
    background: $background;
    border-radius: .1rem;
    transition-property: background;
    transition-duration: .1s;
    transition-timing-function: ease-in-out;
    cursor: pointer;
  |j}
];

[@react.component]
let make = (~isAlive, ~onToggle) =>
  <Wrapper
    onMouseOver={handleMouseEvent(onToggle)}
    onMouseDown={handleMouseEvent(onToggle)}
    background={isAlive ? "#fff" : "#272B30"}
  />;