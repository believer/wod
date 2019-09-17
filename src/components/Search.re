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
  <div className="flex text-gray-700 items-center mt-4 sm:mt-0">
    <div
      className="bg-gray-200 flex items-center px-4 py-3 border-2 border-gray-200
    focus-within:bg-white rounded focus-within:border-blue-400 focus-within:text-blue-700 relative">
      <svg
        className="w-4 mr-4 fill-current"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 20 20">
        <path
          d="M12.9 14.32a8 8 0 1 1 1.41-1.41l5.35 5.33-1.42 1.42-5.33-5.34zM8 14A6 6 0 1 0 8 2a6 6 0 0 0 0 12z"
        />
      </svg>
      <input
        className="appearance-none block w-full bg-transparent text-gray-700
    leading-tight focus:outline-none"
        id="grid-last-name"
        type_="text"
        onChange={e =>
          switch (e->ReactEvent.Form.target##value) {
          | "" => onChange(None)
          | v => onChange(Some(v))
          }
        }
        placeholder="Find workout"
        value={
          switch (query) {
          | Some(value) => value
          | None => ""
          }
        }
      />
    </div>
  </div>;
};
