type t = [
  | `AirSquat
  | `BackwardLunge
  | `BarFacingBurpee
  | `BarMuscleUp
  | `BentOverRow
  | `BoxJump
  | `BoxStepUp
  | `Burpee
  | `BurpeeBoxOver
  | `C2B
  | `Clean
  | `CleanAndJerk
  | `CleanHangPower
  | `CleanPower
  | `Deadlift
  | `DevilPress
  | `DoubleUnder
  | `GroundToOverhead
  | `HangingKneeRaise
  | `KBS
  | `Lunge
  | `OverheadSquat
  | `PullUp
  | `PullUpJumping
  | `PushJerk
  | `PushPress
  | `PushUp
  | `Rest
  | `RingRow
  | `Row
  | `Run
  | `RussianTwist
  | `SingleUnder
  | `SkiErg
  | `SnatchAlt
  | `SnatchHangPower
  | `SnatchPower
  | `Squat
  | `SumoDeadliftHighPull
  | `Thruster
  | `VUps
  | `VUpsSide
  | `WallBall
  | `WeightedStepUp
];

let toString =
  fun
  | `AirSquat => "air squat"
  | `BackwardLunge => "backward lunge"
  | `BarMuscleUp => "bar muscle-ups"
  | `BentOverRow => "bent-over row"
  | `BoxJump => "box jumps"
  | `BoxStepUp => "box step-ups"
  | `Burpee => "burpees"
  | `BurpeeBoxOver => "burpee box overs"
  | `BarFacingBurpee => "bar-facing burpees"
  | `C2B => "C2B pull-ups"
  | `Clean => "clean"
  | `CleanAndJerk => "clean and jerk"
  | `CleanHangPower => "hang power cleans"
  | `CleanPower => "power cleans"
  | `Deadlift => "deadlifts"
  | `DevilPress => "devil presses"
  | `DoubleUnder => "double unders"
  | `GroundToOverhead => "ground to overhead"
  | `HangingKneeRaise => "hanging knee raises"
  | `KBS => "kettlebell swing"
  | `Lunge => "lunge"
  | `OverheadSquat => "overhead squats"
  | `PullUp => "pull-ups"
  | `PullUpJumping => "jumping pull-ups"
  | `PushJerk => "push jerks"
  | `PushPress => "push presses"
  | `PushUp => "push-up"
  | `Rest => "rest"
  | `RingRow => "ring rows"
  | `Row => "row"
  | `Run => "run"
  | `RussianTwist => "russian twist"
  | `SingleUnder => "single unders"
  | `SkiErg => "SkiErg"
  | `SnatchAlt => "alt snatches"
  | `SnatchHangPower => "hang power snatches"
  | `SnatchPower => "power snatch"
  | `Squat => "squat"
  | `SumoDeadliftHighPull => "sumo deadlift high pull"
  | `Thruster => "thrusters"
  | `VUps => "v-ups"
  | `VUpsSide => "side v-ups"
  | `WallBall => "wall balls"
  | `WeightedStepUp => "weighted step-ups";
