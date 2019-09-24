type t = [ | `AMRAP | `EMOM(int) | `AltEMOM(int) | `ForTime | `E90(int)];

let toString: t => string =
  fun
  | `ForTime => "For time"
  | `EMOM(_) => "EMOM"
  | `E90(_) => "E90s"
  | `AltEMOM(min) => "Alt. EMOM " ++ min->string_of_int ++ " min"
  | `AMRAP => "AMRAP";

let toRounds = wodType =>
  switch (wodType) {
  | `E90(minutes) => minutes * 60 / 90
  };
