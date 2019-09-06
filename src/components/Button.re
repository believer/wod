[@react.component]
let make = (~className=?, ~onClick, ~children) => {
  <button
    className={Cn.make([
      "bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded-full",
      className->Cn.unpack,
    ])}
    onClick>
    children
  </button>;
};
