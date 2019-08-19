[@react.component]
let make =
    (~onClick=?, ~children, ~background=`Gray, ~className=?, ~selected=?) => {
  let bg =
    switch (background) {
    | `Gray => "bg-gray-200 text-gray-700"
    | `Red => "bg-red-200 text-red-700"
    };

  let className =
    Css.(
      merge([
        "inline-block rounded-full px-3 py-1 text-sm font-semibold",
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
