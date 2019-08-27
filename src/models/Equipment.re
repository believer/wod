type t = [
  | `Barbell
  | `Dumbbell
  | `Kettlebell
  | `WallBall
  | `BulgarianBag
  | `JumpRope
];

let toString =
  fun
  | `JumpRope => "jump rope"
  | `Barbell => "Barbell"
  | `Dumbbell => "DB"
  | `Kettlebell => "KB"
  | `WallBall => "medicine ball"
  | `BulgarianBag => "bulgarian bag";
