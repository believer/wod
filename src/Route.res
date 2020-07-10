module WodType = {
  type t =
    | EMOM
    | AMRAP
    | ForTime
}

module WodCategory = {
  type t =
    | Hero
    | Girl
    | WZA
    | Open
    | Strength
    | Mayhem
}

type t =
  | Home((option<WodType.t>, option<WodCategory.t>))
  | Glossary
  | NotFoundRoute

module WorkoutType = {
  open WodType

  let fromString = route =>
    switch route {
    | "emom" => Some(EMOM)
    | "for-time" => Some(ForTime)
    | "amrap" => Some(AMRAP)
    | _ => None
    }

  let toString = route =>
    switch route {
    | Some(EMOM) => "emom"
    | Some(ForTime) => "for-time"
    | Some(AMRAP) => "amrap"
    | None => "all"
    }
}

module WorkoutCategory = {
  open WodCategory

  let fromString = category =>
    switch category {
    | "hero" => Some(Hero)
    | "girl" => Some(Girl)
    | "wza" => Some(WZA)
    | "open" => Some(Open)
    | "strength" => Some(Strength)
    | "mayhem" => Some(Mayhem)
    | _ => None
    }

  let toString = category =>
    switch category {
    | Some(Hero) => "hero"
    | Some(Girl) => "girl"
    | Some(WZA) => "wza"
    | Some(Open) => "open"
    | Some(Strength) => "strength"
    | Some(Mayhem) => "mayhem"
    | None => "all"
    }
}

let fromPath = path =>
  switch path {
  | list[] => Home((None, None))
  | list["glossary"] => Glossary
  | list[workoutType, workoutCategory] =>
    Home((
      WorkoutType.fromString(workoutType),
      WorkoutCategory.fromString(workoutCategory),
    ))
  | _ => NotFoundRoute
  }

let toPath = route =>
  switch route {
  | Glossary => "/glossary"
  | Home((None, None)) => "/"
  | Home((wt, wc)) =>
    "/" ++ WorkoutType.toString(wt) ++ "/" ++ WorkoutCategory.toString(wc)
  | NotFoundRoute => "/"
  }

let go = path => path->toPath->ReasonReactRouter.push
