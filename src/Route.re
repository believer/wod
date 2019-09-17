type workoutType =
  | EMOM
  | AMRAP
  | ForTime;

type workoutCategory =
  | Hero
  | Girl
  | WZA
  | Open;
type t =
  | Home((option(workoutType), option(workoutCategory)))
  | Glossary
  | NotFoundRoute;

module WorkoutType = {
  let fromString =
    fun
    | "emom" => Some(EMOM)
    | "for-time" => Some(ForTime)
    | "amrap" => Some(AMRAP)
    | _ => None;

  let toString =
    fun
    | Some(EMOM) => "emom"
    | Some(ForTime) => "for-time"
    | Some(AMRAP) => "amrap"
    | None => "all";
};

module WorkoutCategory = {
  let fromString =
    fun
    | "hero" => Some(Hero)
    | "girl" => Some(Girl)
    | "wza" => Some(WZA)
    | "open" => Some(Open)
    | _ => None;

  let toString =
    fun
    | Some(Hero) => "hero"
    | Some(Girl) => "girl"
    | Some(WZA) => "wza"
    | Some(Open) => "open"
    | None => "all";
};

let fromPath =
  fun
  | [] => Home((None, None))
  | ["glossary"] => Glossary
  | [workoutType, workoutCategory] =>
    Home((
      WorkoutType.fromString(workoutType),
      WorkoutCategory.fromString(workoutCategory),
    ))
  | _ => NotFoundRoute;

let toPath =
  fun
  | Glossary => "/glossary"
  | Home((None, None)) => "/"
  | Home((wt, wc)) =>
    "/" ++ WorkoutType.toString(wt) ++ "/" ++ WorkoutCategory.toString(wc)
  | NotFoundRoute => "/";

let go = path => path->toPath->ReasonReactRouter.push;
