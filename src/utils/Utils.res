let capitalizeFirst = str =>
  (str |> Js.String.charAt(0) |> Js.String.toUpperCase) ++ (str |> Js.String.sliceToEnd(~from=1))

@send external padEndWith: (string, int, string) => string = "padEnd"

@send external padStartWith: (string, int, string) => string = "padStart"

let padEndWithSpace = str => str->padEndWith(str->Js.String.length + 1, " ")

let padStartWithSpace = str => str->padStartWith(str->Js.String.length + 1, " ")

@module external pluralize: string => string = "pluralize"

@val external version: string = "import.meta.env.WOD_VERSION"
