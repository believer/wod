type t = [
  | #AirSquat
  | #BackwardLunge
  | #BarFacingBurpee
  | #BarMuscleUp
  | #BearCrawl
  | #BenchPress
  | #BentOverRow
  | #BoxJump
  | #BoxStepUp
  | #Burpee
  | #BurpeeBoxOver
  | #BurpeeOverRower
  | #ChestToBar
  | #Clean
  | #CleanAndJerk
  | #CleanHangPower
  | #CleanHighPull
  | #CleanPower
  | #CleanSquat
  | #Deadlift
  | #DevilPress
  | #DoubleUnder
  | #DoubleUnderHeavy
  | #GroundToOverhead
  | #FrontSquat
  | #HandReleasePushUp
  | #HandstandPushUp
  | #HandstandPushUpStrict
  | #HandstandPushUpStrictElevated
  | #HandstandWalk
  | #HangingKneeRaise
  | #JerkDipSquat
  | #Lunge
  | #LungeFrontRack
  | #MedicineBallStepUp
  | #MuscleUp
  | #MuscleUpRing
  | #OverheadLunge
  | #OverheadSquat
  | #PullUp
  | #PullUpChinOverBar
  | #PullUpJumping
  | #PushJerk
  | #PushPress
  | #PushUp
  | #Rest
  | #RingDip
  | #RingRow
  | #RopeClimb
  | #RopeClimbLegless
  | #Row
  | #Run
  | #RussianTwist
  | #ShoulderToOverhead
  | #SingleLegSquat
  | #SingleUnder
  | #SitUp
  | #SkiErg
  | #Snatch
  | #SnatchAlt
  | #SnatchHangPower
  | #SnatchMuscle
  | #SnatchPower
  | #SnatchSquat
  | #SplitJerk
  | #Squat
  | #SumoDeadliftHighPull
  | #Swim
  | #Swing
  | #Thruster
  | #ToesToBar
  | #VUps
  | #VUpsSide
  | #WallBall
  | #WeightedStepUp
  | #WeightedButterflySitUp
]

let toString: t => string = exercise =>
  switch exercise {
  | #AirSquat => "air squat"
  | #BackwardLunge => "backward lunge"
  | #BarMuscleUp => "bar muscle-up"
  | #BearCrawl => "bear crawl"
  | #BenchPress => "bench press"
  | #BentOverRow => "bent-over row"
  | #BoxJump => "box jump"
  | #BoxStepUp => "box step-up"
  | #Burpee => "burpee"
  | #BurpeeBoxOver => "burpee box over"
  | #BurpeeOverRower => "burpee over rower"
  | #BarFacingBurpee => "bar-facing burpee"
  | #ChestToBar => "chest-to-bar pull-up"
  | #Clean => "clean"
  | #CleanAndJerk => "clean and jerk"
  | #CleanHangPower => "hang power clean"
  | #CleanHighPull => "clean high pull"
  | #CleanPower => "power clean"
  | #CleanSquat => "squat clean"
  | #Deadlift => "deadlift"
  | #DevilPress => "devil presse"
  | #DoubleUnder => "double under"
  | #DoubleUnderHeavy => "heavy double under"
  | #GroundToOverhead => "ground-to-overhead"
  | #FrontSquat => "front squat"
  | #HandReleasePushUp => "hand-release push-up"
  | #HandstandPushUp => "handstand push-up"
  | #HandstandPushUpStrict => "strict handstand push-up"
  | #HandstandPushUpStrictElevated => "elevated strict handstand push-up"
  | #HandstandWalk => "handstand walk"
  | #HangingKneeRaise => "hanging knee raise"
  | #JerkDipSquat => "jerk dip squat"
  | #Lunge => "lunge"
  | #LungeFrontRack => "front-rack lunge"
  | #MedicineBallStepUp => "medicine-ball step-up"
  | #MuscleUp => "muscle-up"
  | #MuscleUpRing => "ring muscle-up"
  | #OverheadLunge => "overhead lunge"
  | #OverheadSquat => "overhead squat"
  | #PullUp => "pull-up"
  | #PullUpChinOverBar => "chin-over-bar pull-up"
  | #PullUpJumping => "jumping pull-up"
  | #PushJerk => "push jerk"
  | #PushPress => "push press"
  | #PushUp => "push-up"
  | #Rest => "rest"
  | #RingDip => "ring dip"
  | #RingRow => "ring row"
  | #RopeClimb => "rope climb"
  | #RopeClimbLegless => "legless rope climb"
  | #Row => "row"
  | #Run => "run"
  | #RussianTwist => "russian twist"
  | #ShoulderToOverhead => "shoulder-to-overhead"
  | #SingleLegSquat => "single-leg squat"
  | #SingleUnder => "single under"
  | #SitUp => "sit-up"
  | #SkiErg => "SkiErg"
  | #Snatch => "snatch"
  | #SnatchAlt => "alt snatch"
  | #SnatchHangPower => "hang power snatch"
  | #SnatchPower => "power snatch"
  | #SnatchMuscle => "muscle snatch"
  | #SnatchSquat => "squat snatch"
  | #SplitJerk => "split jerk"
  | #Squat => "squat"
  | #SumoDeadliftHighPull => "sumo deadlift high pull"
  | #Swim => "swim"
  | #Swing => "swing"
  | #Thruster => "thruster"
  | #ToesToBar => "toes-to-bar"
  | #VUps => "v-up"
  | #VUpsSide => "side v-up"
  | #WallBall => "wall ball"
  | #WeightedStepUp => "weighted step-up"
  | #WeightedButterflySitUp => "weighted butterfly sit-up"
  }
