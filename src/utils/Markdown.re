[@bs.module] external marked: string => string = "marked";

[@react.component]
let make = (~className=?, ~text) => {
  <div
    className={className->Cn.unpack}
    dangerouslySetInnerHTML={"__html": marked(text)}
  />;
};
