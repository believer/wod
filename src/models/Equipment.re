type t = [ | `Barbell | `Dumbbell | `Kettlebell | `WallBall | `BulgarianBag];

let toString =
  fun
  | `Barbell => "Barbell"
  | `Dumbbell => "DB"
  | `Kettlebell => "KB"
  | `WallBall => "medicine ball"
  | `BulgarianBag => "bulgarian bag";
