let capitalizeFirst = str =>
  (str |> Js.String.charAt(0) |> Js.String.toUpperCase)
  ++ (str |> Js.String.sliceToEnd(~from=1));
