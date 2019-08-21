type categoryStyle = [ | `RX | `Scaled];

type t = [
  | `Hero
  | `Girl
  | `Wodapalooza(int)
  | `Open(int, int, categoryStyle)
];
