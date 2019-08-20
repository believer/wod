type t = [ | `AMRAP | `EMOM | `ForTime];

let toString =
  fun
  | `ForTime => "For time"
  | `EMOM => "EMOM"
  | `AMRAP => "AMRAP";
