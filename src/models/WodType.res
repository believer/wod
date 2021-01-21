type t = [#AMRAP | #EMOM(int) | #AltEMOM(int) | #ForTime | #E90(int) | #ForDistance]

let toString: t => string = wodType =>
  switch wodType {
  | #ForTime => "For time"
  | #ForDistance => "For max meters"
  | #EMOM(_) => "EMOM"
  | #E90(_) => "E90s"
  | #AltEMOM(min) => "Alt. EMOM " ++ min->string_of_int ++ " min"
  | #AMRAP => "AMRAP"
  }

let toRounds = wodType =>
  switch wodType {
  | #E90(minutes) => minutes * 60 / 90
  }
