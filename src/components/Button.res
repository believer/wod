@react.component
let make = (~className=?, ~onClick, ~children) => {
  <button
    className={Cn.fromList(list{
      "bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded-full
        focus:bg-blue-700",
      className->Cn.take,
    })}
    onClick>
    children
  </button>
}
