module Dedent = {
  [@bs.module] external make: string => string = "dedent";
};

module Parser = {
  [@bs.module] external make: string => string = "marked";
};

module Element = {
  [@bs.module "react-html-parser"]
  external make: string => React.element = "default";
};

[@react.component]
let make = (~className=?, ~text) => {
  <div className={Cn.make(["markdown", className->Cn.unpack])}>
    {text->Dedent.make->Parser.make->Element.make}
  </div>;
};
