type t = [
  | `AirSquat
  | `BackwardLunge
  | `BoxJump
  | `BoxStepUp
  | `Burpee
  | `BurpeeBoxOver
  | `BarFacingBurpee
  | `BentOverRow
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
  | `PushJerk
  | `PushPress
  | `PushUp
  | `Rest
  | `Row
  | `Run
  | `RussianTwist
  | `SingleUnder
  | `SkiErg
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
  | `BentOverRow => "bent-over row"
  | `BoxJump => "box jumps"
  | `BoxStepUp => "box step-ups"
  | `Burpee => "burpees"
  | `BurpeeBoxOver => "burpee box overs"
  | `BarFacingBurpee => "bar-facing burpees"
  | `Clean => "clean"
  | `CleanAndJerk => "clean and jerk"
  | `CleanHangPower => "hang power cleans"
  | `CleanPower => "power cleans"
  | `Deadlift => "deadlifts"
  | `DevilPress => "devil press"
  | `DoubleUnder => "double unders"
  | `GroundToOverhead => "ground to overhead"
  | `HangingKneeRaise => "hanging knee raises"
  | `KBS => "kettlebell swing"
  | `Lunge => "lunge"
  | `OverheadSquat => "overhead squats"
  | `PullUp => "pull-up"
  | `PushJerk => "push jerk"
  | `PushPress => "push press"
  | `PushUp => "push-up"
  | `Rest => "rest"
  | `Row => "row"
  | `Run => "run"
  | `RussianTwist => "russian twist"
  | `SingleUnder => "single unders"
  | `SkiErg => "SkiErg"
  | `SnatchHangPower => "hang power snatches"
  | `SnatchPower => "power snatch"
  | `Squat => "squat"
  | `SumoDeadliftHighPull => "sumo deadlift high pull"
  | `Thruster => "thrusters"
  | `VUps => "v-ups"
  | `VUpsSide => "side v-ups"
  | `WallBall => "wall balls"
  | `WeightedStepUp => "weighted step-ups";
