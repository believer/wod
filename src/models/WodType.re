type t = [ | `AMRAP | `EMOM(int) | `AltEMOM(int) | `ForTime];

let toString =
  fun
  | `ForTime => "For time"
  | `EMOM(_) => "EMOM"
  | `AltEMOM(min) => "Alt. EMOM " ++ min->string_of_int ++ " min"
  | `AMRAP => "AMRAP";
