module Exercise = {
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
};

module WodPart = {
  type t = {
    weight: (option(Weight.t), option(Weight.t)),
    reps: ExerciseUnit.t,
    exercise: Exercise.t,
    equipment: option(Equipment.t),
  };
};

module RepScheme = {
  type t = list(int);
};

type t = {
  category: option(Category.t),
  buyInOut: option((option(WodPart.t), option(WodPart.t))),
  createdAt: string,
  description: option(string),
  id: string,
  externalLink: option((string, string)),
  name: option(string),
  wodType: WodType.t,
  timeCap: option(int),
  rounds: option(int),
  repScheme: option(RepScheme.t),
  parts: list(WodPart.t),
};

let wods = [
  {
    id: "dfa983fb-1fdb-4b67-8b8c-a15184798dc4",
    buyInOut: None,
    category: None,
    createdAt: "2019-08-18T22:00:00.000Z",
    description: None,
    name: None,
    externalLink: None,
    wodType: `AMRAP,
    timeCap: Some(30),
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Meter(500),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg(20)), Some(`kg(15))),
        exercise: `PushPress,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg2(15)), Some(`kg2(12))),
        exercise: `BackwardLunge,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg(16)), Some(`kg(12))),
        exercise: `KBS,
        equipment: Some(`Kettlebell),
      },
      {
        reps: `Num(10),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `VUps,
        equipment: None,
      },
    ],
  },
  {
    id: "d2b07e7e-a1c1-487e-ad5a-ec9dd89d5fd4",
    name: None,
    buyInOut: None,
    category: None,
    createdAt: "2019-08-18T22:00:00.000Z",
    description: None,
    externalLink: None,
    wodType: `ForTime,
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(10),
        weight: (Some(`kg(9)), Some(`kg(6))),
        exercise: `WallBall,
        equipment: Some(`WallBall),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg(15)), Some(`kg(12))),
        exercise: `Clean,
        equipment: Some(`BulgarianBag),
      },
    ],
  },
  {
    id: "22cdb52b-bb43-4848-957b-5d1006560e78",
    createdAt: "2019-08-18T22:00:00.000Z",
    name: None,
    buyInOut: None,
    externalLink: None,
    wodType: `ForTime,
    category: None,
    description: None,
    timeCap: None,
    rounds: Some(10),
    repScheme: None,
    parts: [
      {
        reps: `Cal(9),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `Num(6),
        weight: (Some(`cm(60)), Some(`cm(45))),
        exercise: `BoxJump,
        equipment: None,
      },
      {
        reps: `Num(3),
        weight: (Some(`kg(15)), Some(`kg(10))),
        exercise: `DevilPress,
        equipment: Some(`Dumbbell),
      },
    ],
  },
  {
    id: "dt",
    createdAt: "2019-08-18T22:00:00.000Z",
    name: Some("DT"),
    buyInOut: None,
    externalLink: None,
    wodType: `ForTime,
    category: Some(`Hero),
    description:
      Some(
        "In honor of US Air Force SSgt Timothy P. Davis, 28, who
    was killed on Feburary, 20 2009 supporting operations in OEF when his vehicle was struck by an IED.",
      ),
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(12),
        weight: (Some(`kg(70)), Some(`kg(47))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(9),
        weight: (Some(`kg(70)), Some(`kg(47))),
        exercise: `CleanHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(6),
        weight: (Some(`kg(70)), Some(`kg(47))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "half-murph",
    createdAt: "2019-08-18T22:00:00.000Z",
    name: Some("Half Murph"),
    wodType: `ForTime,
    externalLink: None,
    buyInOut: None,
    category: Some(`Hero),
    description:
      Some(
        "In memory of Navy Lieutenant Michael P. Murphy, who was killed in Afghanistan June 28, 2005. Murphy was awarded the U.S. military's highest decoration, the Medal of Honor, for his actions during the War in Afghanistan.",
      ),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Meter(800),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `Run,
        equipment: None,
      },
      {
        reps: `Num(50),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(100),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(150),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
      {
        reps: `Meter(800),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `Run,
        equipment: None,
      },
    ],
  },
  {
    id: "chip-through-monday",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: Some("Chip Through Monday"),
    wodType: `ForTime,
    category: None,
    buyInOut: None,
    externalLink: None,
    description: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
      {
        reps: `Num(10),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `Thruster,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
      {
        reps: `Num(15),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `SumoDeadliftHighPull,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
      {
        reps: `Num(20),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushPress,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
      {
        reps: `Num(25),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `CleanHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
      {
        reps: `Num(30),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
    ],
  },
  {
    id: "ski-school",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: Some("Ski School"),
    wodType: `ForTime,
    buyInOut: None,
    category: Some(`Wodapalooza(2018)),
    externalLink: None,
    description:
      Some("For every break on single unders, add 5 cal to last Ski-Erg"),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Cal2((30, 20)),
        weight: (None, None),
        exercise: `SkiErg,
        equipment: None,
      },
      {
        reps: `Num(75),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(75),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(75),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Cal2((30, 20)),
        weight: (None, None),
        exercise: `SkiErg,
        equipment: None,
      },
    ],
  },
  {
    id: "2d1574ad-daf0-41f2-bb18-af0e57fdb136",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: None,
    buyInOut: None,
    wodType: `ForTime,
    externalLink: None,
    category: None,
    description: None,
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(100),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(5),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `SnatchPower,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "waterworks",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: Some("Waterworks"),
    wodType: `ForTime,
    category: None,
    externalLink: None,
    buyInOut: None,
    description: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Cal2((50, 35)),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `Num(40),
        weight: (Some(`kg(24)), Some(`kg(16))),
        exercise: `KBS,
        equipment: Some(`Kettlebell),
      },
      {
        reps: `Num(30),
        weight: (Some(`kg(50)), Some(`kg(35))),
        exercise: `PushPress,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(40),
        weight: (Some(`kg(24)), Some(`kg(16))),
        exercise: `KBS,
        equipment: Some(`Kettlebell),
      },
      {
        reps: `Cal2((50, 35)),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
    ],
  },
  {
    id: "da5ae974-deeb-4205-a80b-1ad2529459da",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: None,
    externalLink: None,
    wodType: `AltEMOM(24),
    category: None,
    description: None,
    timeCap: None,
    buyInOut: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Span((`Num(8), `Num(12))),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `HangingKneeRaise,
        equipment: None,
      },
      {
        reps: `Span((`Cal(6), `Cal(14))),
        weight: (None, None),
        exercise: `SkiErg,
        equipment: None,
      },
      {
        reps: `Span((`OneSide((8, 8)), `OneSide((14, 14)))),
        weight: (Some(`kg(15)), Some(`kg(10))),
        exercise: `RussianTwist,
        equipment: None,
      },
      {
        reps: `Span((`Num(5), `Num(10))),
        weight: (Some(`kg2(12)), Some(`kg2(8))),
        exercise: `BurpeeBoxOver,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Span((`OneSide((6, 6)), `OneSide((9, 9)))),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `VUpsSide,
        equipment: None,
      },
      {
        reps: `Span((`Cal(6), `Cal(14))),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
    ],
  },
  {
    id: "5b09b0e8-52a9-4446-9b9e-2879320d8a8c",
    createdAt: "2019-08-20T22:00:00.000Z",
    name: None,
    buyInOut: None,
    wodType: `ForTime,
    category: None,
    externalLink: None,
    description: Some("Rest 3 min between rounds"),
    timeCap: None,
    rounds: Some(2),
    repScheme: Some([21, 15, 9]),
    parts: [
      {
        reps: `RepScheme,
        weight: (None, None),
        exercise: `SkiErg,
        equipment: None,
      },
      {
        reps: `RepScheme,
        weight: (Some(`kg(9)), Some(`kg(6))),
        exercise: `WallBall,
        equipment: Some(`WallBall),
      },
    ],
  },
  {
    id: "bd199c6f-bfa3-484d-b703-1361f9bef768",
    createdAt: "2019-08-20T22:00:00.000Z",
    name: None,
    buyInOut: None,
    wodType: `ForTime,
    category: Some(`Open((18, 2, `Scaled))),
    externalLink: None,
    description:
      Some(
        "After all rounds are complete establish a 1-rep-max clean in remaining time",
      ),
    timeCap: Some(12),
    rounds: None,
    repScheme: Some([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    parts: [
      {
        reps: `RepScheme,
        weight: (Some(`kg2(15)), Some(`kg2(10))),
        exercise: `Squat,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarFacingBurpee,
        equipment: None,
      },
    ],
  },
  {
    id: "0394b4ee-983d-4d54-8f5a-9466cdb5c609",
    createdAt: "2019-08-20T22:00:00.000Z",
    name: None,
    buyInOut: None,
    wodType: `ForTime,
    category: None,
    description: None,
    externalLink: None,
    timeCap: Some(6),
    rounds: None,
    repScheme: Some([100, 10, 80, 8, 60, 6, 40, 4, 20, 2]),
    parts: [
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `RepScheme,
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushPress,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "grace",
    createdAt: "2019-08-21T22:00:00.000Z",
    name: Some("Grace"),
    wodType: `ForTime,
    buyInOut: None,
    category: Some(`Girl),
    description: None,
    externalLink: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(30),
        weight: (Some(`kg(61)), Some(`kg(43))),
        exercise: `CleanAndJerk,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "5942a30a-eedf-402f-8ba7-267ea0713efc",
    createdAt: "2019-08-21T22:00:00.000Z",
    name: None,
    wodType: `ForTime,
    category: None,
    buyInOut: None,
    externalLink: None,
    description: None,
    timeCap: None,
    rounds: Some(3),
    repScheme: None,
    parts: [
      {
        reps: `Num(15),
        weight: (Some(`kg2(15)), Some(`kg2(10))),
        exercise: `PushJerk,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Num(50),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(15),
        weight: (Some(`kg2cm((15, 60))), Some(`kg2cm((10, 45)))),
        exercise: `WeightedStepUp,
        equipment: None,
      },
      {
        reps: `Num(50),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `SingleUnder,
        equipment: None,
      },
    ],
  },
  {
    id: "keithroy-maynard",
    createdAt: "2019-08-22T22:00:00.000Z",
    name: Some("Keithroy Maynard"),
    wodType: `ForTime,
    buyInOut: None,
    category: Some(`Hero),
    externalLink: None,
    description:
      Some(
        {j|
Wear a weighted west if available. On the last round, do 15 air squats.

This Firefighter Hero WOD is dedicated to Keithroy Maynard, FDNY, Engine 33, who was killed on September 11, 2001.
        |j},
      ),
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(44),
        weight: (Some(`cm(60)), Some(`cm(45))),
        exercise: `BoxStepUp,
        equipment: None,
      },
      {
        reps: `Num(12),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(12),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
    ],
  },
  {
    id: "7-7-7",
    createdAt: "2019-08-24T10:05:54.996Z",
    name: Some("7-7-7"),
    wodType: `ForTime,
    category: None,
    buyInOut: None,
    description: None,
    externalLink: None,
    timeCap: None,
    rounds: Some(7),
    repScheme: None,
    parts: [
      {
        reps: `Num(7),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(7),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `Thruster,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(7),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `Burpee,
        equipment: None,
      },
    ],
  },
  {
    id: "a6b8a163-ae96-47fd-a8e6-bd0c21ae1781",
    createdAt: "2019-08-24T10:10:43.893Z",
    name: None,
    wodType: `AMRAP,
    category: None,
    externalLink: None,
    buyInOut:
      Some((
        Some({
          reps: `Meter(500),
          weight: (None, None),
          exercise: `Row,
          equipment: None,
        }),
        Some({
          reps: `Meter(500),
          weight: (None, None),
          exercise: `SkiErg,
          equipment: None,
        }),
      )),
    description: None,
    timeCap: Some(8),
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg(15)), Some(`kg(10))),
        exercise: `Lunge,
        equipment: Some(`BulgarianBag),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg2(15)), Some(`kg2(10))),
        exercise: `GroundToOverhead,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg2(15)), Some(`kg2(10))),
        exercise: `BentOverRow,
        equipment: Some(`Dumbbell),
      },
    ],
  },
  {
    id: "190617-mayhem",
    createdAt: "2019-08-27T16:37:11.543Z",
    name: Some("190617-Mayhem"),
    wodType: `EMOM(23),
    category: None,
    buyInOut: None,
    externalLink:
      Some((
        "CrossFit Mayhem",
        "https://www.crossfitmayhem.com/daily-workout-posts/2019/6/16/6172019",
      )),
    description:
      Some(
        {j|
  Each set EMOM 5 min, then 1 min rest before next EMOM.

  * First set (5 reps) light weight, touch and go
  * Second set (3 reps) medium weight, touch and go
  * Third set (1 rep - E30s) heavy weight
  * Last set (5 reps) same as first set
    |j},
      ),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(5),
        weight: (None, None),
        exercise: `SnatchPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(3),
        weight: (None, None),
        exercise: `SnatchPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(1),
        weight: (None, None),
        exercise: `SnatchPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(5),
        weight: (None, None),
        exercise: `SnatchPower,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "190617-mayhem-clean",
    createdAt: "2019-08-27T16:51:40.140Z",
    name: Some("190617-Mayhem with Cleans"),
    wodType: `EMOM(23),
    externalLink: None,
    category: None,
    buyInOut: None,
    description:
      Some(
        {j|
  Each set EMOM 5 min, then 1 min rest before next EMOM.

  * First set (5 reps) light weight, touch and go
  * Second set (3 reps) medium weight, touch and go
  * Third set (1 rep - E30s) heavy weight
  * Last set (5 reps) same as first set
    |j},
      ),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(5),
        weight: (None, None),
        exercise: `CleanPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(3),
        weight: (None, None),
        exercise: `CleanPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(1),
        weight: (None, None),
        exercise: `CleanPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Min(1),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
      {
        reps: `Num(5),
        weight: (None, None),
        exercise: `CleanPower,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "wzaoc191",
    createdAt: "2019-08-27T16:51:40.140Z",
    name: Some("WZAOC 1"),
    wodType: `EMOM(23),
    category: Some(`Wodapalooza(2019)),
    buyInOut: None,
    externalLink:
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-1/",
      )),
    description:
      Some(
        {j|
Add 3 repetitions to each of the barbell movements (3/3/30, 6/6/30, 9/9/30, 12/12/30... etc..) at the conclusion of each round.<Paste>
    |j},
      ),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Increasing(3),
        weight: (Some(`kg(34)), Some(`kg(25))),
        exercise: `SnatchHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Increasing(3),
        weight: (Some(`kg(34)), Some(`kg(25))),
        exercise: `OverheadSquat,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(30),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `DoubleUnder,
        equipment: Some(`JumpRope),
      },
    ],
  },
];
