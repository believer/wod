[@bs.module] external marked: string => string = "marked";

[@react.component]
let make = (~text) => {
  <div
    className="mt-4 text-xs text-gray-500 markdown"
    dangerouslySetInnerHTML={"__html": marked(text)}
  />;
};
