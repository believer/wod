type t =
  | Barbell
  | Dumbbell
  | Kettlebell
  | WallBall
  | BulgarianBag
  | JumpRope
  | Unbroken

let toString = equipment =>
  switch equipment {
  | JumpRope => "jump rope"
  | Barbell => "Barbell"
  | Dumbbell => "DB"
  | Kettlebell => "KB"
  | WallBall => "medicine ball"
  | BulgarianBag => "bulgarian bag"
  | Unbroken => "UB"
  }
