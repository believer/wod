@react.component
let make = (~text, ~onClick) => {
  <button
    className="inline-flex items-center bg-gray-200 text-gray-700 text-sm px-4
    py-3 rounded inline-block hover:bg-gray-300"
    onClick
    role="alert"
    type_="button">
    <Markdown text />
    <svg
      className="w-4 h-4 ml-2"
      xmlns="http://www.w3.org/2000/svg"
      viewBox="0 0 20 20">
      <path
        className="fill-current"
        d="M10 8.586L2.929 1.515 1.515 2.929 8.586 10l-7.071 7.071 1.414 1.414L10 11.414l7.071 7.071 1.414-1.414L11.414 10l7.071-7.071-1.414-1.414L10 8.586z"
      />
    </svg>
  </button>
}
