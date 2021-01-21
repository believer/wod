module Dedent = {
  @module external make: string => string = "dedent"
}

module Parser = {
  @module external make: string => string = "marked"
}

module Element = {
  @module("react-html-parser")
  external make: string => React.element = "default"
}

@react.component
let make = (~className=?, ~text) => {
  <div className={Cn.fromList(list{"markdown", className->Cn.take})}>
    {text->Dedent.make->Parser.make->Element.make}
  </div>
}
