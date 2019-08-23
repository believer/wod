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
