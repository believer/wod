module Item = {
  type t('value) = {
    value: option('value),
    label: string,
  };

  let make = (~value=None, ~label, ()) => {value, label};
};

let matchSelected = (value, matcher) =>
  switch (value) {
  | None => Belt.Option.isNone(matcher)
  | Some(value) => matcher === Some(value)
  };

[@react.component]
let make = (~onClick=?, ~children, ~color=`Gray, ~className=?, ~selected=?) => {
  let bg =
    switch (color) {
    | `Gray => "bg-gray-200 text-gray-700"
    | `Red => "bg-red-200 text-red-700"
    | `Green => "bg-green-200 text-green-700"
    | `Pink => "bg-pink-200 text-pink-700"
    | `Indigo => "bg-indigo-200 text-indigo-700"
    | `Blue => "bg-blue-200 text-blue-700"
    | `Purple => "bg-purple-200 text-purple-700"
    };

  let className =
    Css.(
      merge([
        "inline-block rounded-full px-3 py-1 text-sm font-semibold text-center
        mr-4 last:mr-0",
        bg,
        className->Cn.unpack,
        {
          switch (selected) {
          | Some(selected) =>
            "bg-blue-200 text-blue-700"->Cn.ifTrue(selected)
          | None => ""
          };
        },
      ])
    );

  switch (onClick) {
  | Some(onClick) => <button className onClick> children </button>
  | None => <div className> children </div>
  };
};
