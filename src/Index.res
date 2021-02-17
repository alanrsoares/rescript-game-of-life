%raw(`require("./index.css")`)

@module("./serviceWorker")
external register_service_worker: unit => unit = "register"

let randomSeed = Js.Date.now()->int_of_float

let fallback = <div> {React.string("...")} </div>
let app = <React.Suspense fallback> <App key="app" /> </React.Suspense>

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(app, root)
| None => ()
}

register_service_worker()
