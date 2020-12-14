%bs.raw(`require("./index.css")`)

@bs.module("./serviceWorker")
external register_service_worker: unit => unit = "register"

let randomSeed = Js.Date.now()->int_of_float

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(<App />, root)
| None => ()
}

register_service_worker()
