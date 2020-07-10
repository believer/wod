@bs.module("localforage")
external setItem: (string, string) => Js.Promise.t<string> = "setItem"

@bs.module("localforage")
external getItem: string => Js.Promise.t<string> = "getItem"

let set = (key, value) => setItem(key, value)
let get = key => getItem(key)

let useStorage = (~initialValue, ~key, ~parser) => {
  open Js.Promise

  let (value, setValue) = React.useState(() => initialValue)

  React.useEffect0(() => {
    get(key)
    |> then_(value => {
         setValue(_ => parser(value))
         resolve()
       })
    |> ignore

    None
  })

  let handleSet = value => {
    setValue(_ => parser(value))
    set(key, value) |> ignore
  }

  (value, handleSet)
}
