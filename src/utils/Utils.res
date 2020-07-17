let capitalizeFirst = str =>
  (str |> Js.String.charAt(0) |> Js.String.toUpperCase) ++ (str |> Js.String.sliceToEnd(~from=1))

@bs.send.pipe(: Js.String.t) external padEndWith: (int, string) => string = "padEnd"

@bs.send.pipe(: Js.String.t) external padStartWith: (int, string) => string = "padStart"

let padEndWithSpace = str => str |> padEndWith(str->Js.String.length + 1, " ")

let padStartWithSpace = str => str |> padStartWith(str->Js.String.length + 1, " ")

@bs.module external pluralize: string => string = "pluralize"

@bs.val external version: string = "process.env.WOD_VERSION"
