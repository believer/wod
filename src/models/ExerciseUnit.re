type t = [
  | `Meter(int)
  | `OneSide(int, int)
  | `Num(int)
  | `Cal(int)
  | `Cal2(int, int)
  | `Span(t, t)
];
