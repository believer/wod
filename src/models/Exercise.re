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
  | `BurpeeOverRower
  | `C2B
  | `Clean
  | `CleanAndJerk
  | `CleanHangPower
  | `CleanPower
  | `CleanSquat
  | `Deadlift
  | `DevilPress
  | `DoubleUnder
  | `DoubleUnderHeavy
  | `GroundToOverhead
  | `HangingKneeRaise
  | `HandstandPushUp
  | `KBS
  | `Lunge
  | `MuscleUp
  | `OverheadSquat
  | `PullUp
  | `PullUpJumping
  | `PushJerk
  | `PushPress
  | `PushUp
  | `Rest
  | `RingDip
  | `RingRow
  | `Row
  | `Run
  | `RussianTwist
  | `ShoulderToOverhead
  | `SingleUnder
  | `SitUp
  | `SkiErg
  | `SnatchAlt
  | `SnatchHangPower
  | `SnatchPower
  | `SnatchSquat
  | `Squat
  | `SumoDeadliftHighPull
  | `Swim
  | `Thruster
  | `ToesToBar
  | `VUps
  | `VUpsSide
  | `WallBall
  | `WeightedStepUp
  | `WeightedButterflySitUp
];

let toString =
  fun
  | `AirSquat => "air squat"
  | `BackwardLunge => "backward lunge"
  | `BarMuscleUp => "bar muscle-up"
  | `BentOverRow => "bent-over row"
  | `BoxJump => "box jump"
  | `BoxStepUp => "box step-up"
  | `Burpee => "burpee"
  | `BurpeeBoxOver => "burpee box over"
  | `BurpeeOverRower => "burpee over rower"
  | `BarFacingBurpee => "bar-facing burpee"
  | `C2B => "C2B pull-up"
  | `Clean => "clean"
  | `CleanAndJerk => "clean and jerk"
  | `CleanHangPower => "hang power clean"
  | `CleanPower => "power clean"
  | `CleanSquat => "squat clean"
  | `Deadlift => "deadlift"
  | `DevilPress => "devil presse"
  | `DoubleUnder => "double under"
  | `DoubleUnderHeavy => "heavy double under"
  | `GroundToOverhead => "ground-to-overhead"
  | `HandstandPushUp => "handstand push-up"
  | `HangingKneeRaise => "hanging knee raise"
  | `KBS => "kettlebell swing"
  | `Lunge => "lunge"
  | `MuscleUp => "muscle-up"
  | `OverheadSquat => "overhead squat"
  | `PullUp => "pull-up"
  | `PullUpJumping => "jumping pull-up"
  | `PushJerk => "push jerk"
  | `PushPress => "push press"
  | `PushUp => "push-up"
  | `Rest => "rest"
  | `RingDip => "ring dip"
  | `RingRow => "ring row"
  | `Row => "row"
  | `Run => "run"
  | `RussianTwist => "russian twist"
  | `ShoulderToOverhead => "shoulder-to-overhead"
  | `SingleUnder => "single under"
  | `SitUp => "sit-up"
  | `SkiErg => "SkiErg"
  | `SnatchAlt => "alt snatch"
  | `SnatchHangPower => "hang power snatch"
  | `SnatchPower => "power snatch"
  | `SnatchSquat => "squat snatch"
  | `Squat => "squat"
  | `SumoDeadliftHighPull => "sumo deadlift high pull"
  | `Swim => "swim"
  | `Thruster => "thruster"
  | `ToesToBar => "toes-to-bar"
  | `VUps => "v-up"
  | `VUpsSide => "side v-up"
  | `WallBall => "wall ball"
  | `WeightedStepUp => "weighted step-up"
  | `WeightedButterflySitUp => "weighted butterfly sit-up";
