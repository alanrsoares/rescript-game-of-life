module Root = %styled.div(`
  display: flex;
  color: white;
`)

module AppBar = %styled.div(`
  display: flex;
  text-align: center;
  justify-content: center;
  align-items: center;
  padding-top: 2rem;
  font-size: 2rem;
  line-height: 1rem;
`)

module Content = %styled.div(`
  width: 100%;
`)

module Icon = {
  @react.component
  let make = (~name) => <i className={"fas fa-" ++ name} />
}

module Button = {
  @react.component
  let make = (~label, ~background, ~onClick, ~disabled=false, ~children) => {
    let shadow = Util.Colors.opacify(-0.4, background)
    let pseudoOutline = j`0 0 0 4px $shadow`
    let transition = "all .15s ease-in"

    let className = %css(j`
        font-size: .9rem;
        padding: .5rem .8rem;
        background-color: $background;
        width: 3rem;
        height: 3rem;
        color: white;
        border-radius: 50%;
        margin: 0 .5rem;
        border-width: 0;
        user-select: none;
        outline: 0rem none white;
        font-weight: 700;
        cursor: pointer;
        transition: $transition;
        :focus {
          box-shadow: $pseudoOutline;
          opacity: .9;
        }
      `)

    <button ariaLabel=label className disabled onClick> children </button>
  }
}

module ToggleButton = {
  @react.component
  let make = (~isToggled, ~onClick, ~label, ~disabled=false) => {
    let background = isToggled ? "#666" : "#7A8288"
    let name = isToggled ? "pause" : "play"

    <Button label background onClick disabled> <Icon name /> </Button>
  }
}
