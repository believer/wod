type system =
  | Metric
  | Imperial

type t = {system: system}

let toString = system =>
  switch system {
  | Metric => "metric"
  | Imperial => "imperial"
  }

let fromString = str =>
  switch str {
  | "metric" => Metric
  | _ => Imperial
  }

module Context = {
  include ReactContext.Make({
    type context = t

    let defaultValue = {system: Metric}
  })
}
