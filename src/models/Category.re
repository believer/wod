type categoryStyle = [ | `RX | `Scaled];

type t = [
  | `Hero
  | `Girl
  | `Mayhem
  | `Wodapalooza(int)
  | `Open(int, int, categoryStyle)
  | `Strength
];
