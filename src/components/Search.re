let filter = (query, name) =>
  Js.String.(
    switch (query, name) {
    | (Some(q), Some(n)) => includes(q->toLowerCase, n->toLowerCase)
    | (Some(_), None) => false
    | (None, Some(_))
    | (None, None) => true
    }
  );

[@react.component]
let make = (~query, ~onChange) => {
  let className = Css.(merge(["mb-8", style([gridColumn(3, 4)])]));

  <div className>
    <input
      className="bg-transparent text-lg text-gray-700 border-b w-full py-4"
      onChange
      placeholder="Search"
      type_="text"
      value={
        switch (query) {
        | Some(value) => value
        | None => ""
        }
      }
    />
  </div>;
};
