open Css

module Item = {
  type t<'value> = {
    value: option<'value>,
    label: string,
  }

  let make = (~value=None, ~label, ()) => {value, label}
}

let matchSelected = (value, matcher) =>
  switch (value) {
  | None => Belt.Option.isNone(matcher)
  | Some(value) => matcher === Some(value)
  }

let backgroundColor = color => 
  switch color {
  | #Gray => "bg-gray-200 text-gray-700 hover:bg-gray-300"
  | #Red => "bg-red-200 text-red-700 hover:bg-red-300"
  | #Green => "bg-green-200 text-green-700 hover:bg-green-300"
  | #Pink => "bg-pink-200 text-pink-700 hover:bg-pink-300"
  | #Indigo => "bg-indigo-200 text-indigo-700 hover:bg-indigo-300"
  | #Blue => "bg-blue-200 text-blue-700 hover:bg-blue-300"
  | #Purple => "bg-purple-200 text-purple-700 hover:bg-purple-300"
  }

@react.component
let make = (~onClick=?, ~children, ~color=#Gray, ~className=?, ~selected=?) => {
  let className =
    merge(list{ "inline-block rounded-full px-3 py-1 text-sm font-semibold text-center
        mr-4 last:mr-0",
        backgroundColor(color),
        className->Cn.take,
        {
        switch (selected) {
        | Some(selected) =>
        "bg-blue-200 text-blue-700 hover:bg-blue-300"->Cn.on(selected)
        | None => ""
        }
        },
        })

  switch (onClick) {
  | Some(onClick) => <button className onClick> children </button>
  | None => <div className> children </div>
  }
}
