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
  description: option((option(string), option(string))),
  id: string,
  externalLink: option((string, string)),
  name: option(string),
  wodType: WodType.t,
  timeCap: option(int),
  rounds: option(int),
  repScheme: option(RepScheme.t),
  parts: list(WodPart.t),
  scaledParts: option(list(WodPart.t)),
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
    scaledParts: None,
    parts: [
      {
        reps: `Meter(500),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg(20.0)), Some(`kg(15.0))),
        exercise: `PushPress,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg2(15.0)), Some(`kg2(12.0))),
        exercise: `BackwardLunge,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`kg(16.0)), Some(`kg(12.0))),
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
    scaledParts: None,
    externalLink: None,
    wodType: `ForTime,
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(10),
        weight: (Some(`kg(9.0)), Some(`kg(6.0))),
        exercise: `WallBall,
        equipment: Some(`WallBall),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg(15.0)), Some(`kg(12.0))),
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
    scaledParts: None,
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
        weight: (Some(`cm(60.0)), Some(`cm(45.0))),
        exercise: `BoxJump,
        equipment: None,
      },
      {
        reps: `Num(3),
        weight: (Some(`kg(15.0)), Some(`kg(10.0))),
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
    scaledParts: None,
    category: Some(`Hero),
    description:
      Some((
        Some(
          "In honor of US Air Force SSgt Timothy P. Davis, 28, who
    was killed on Feburary, 20 2009 supporting operations in OEF when his vehicle was struck by an IED.",
        ),
        None,
      )),
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(12),
        weight: (Some(`kg(70.0)), Some(`kg(47.0))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(9),
        weight: (Some(`kg(70.0)), Some(`kg(47.0))),
        exercise: `CleanHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(6),
        weight: (Some(`kg(70.0)), Some(`kg(47.0))),
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
    scaledParts: None,
    buyInOut: None,
    category: Some(`Hero),
    description:
      Some((
        Some(
          "In memory of Navy Lieutenant Michael P. Murphy, who was killed in
             Afghanistan June 28, 2005. Murphy was awarded the U.S. military's
             highest decoration, the Medal of Honor, for his actions during the
             War in Afghanistan.",
        ),
        None,
      )),
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
    scaledParts: None,
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
    id: "wza-ski-school",
    createdAt: "2019-08-19T22:00:00.000Z",
    name: Some("Ski School"),
    wodType: `ForTime,
    buyInOut: None,
    category: Some(`Wodapalooza(2018)),
    externalLink:
      Some(("Wodapalooza", "https://wodapalooza.com/workout/ski-school/")),
    description:
      Some((
        Some(
          {j|
For every break on jump rope, add 5 cal to last Ski-Erg.

Scaled may exchange singles to 25 dubs.
        |j},
        ),
        None,
      )),
    timeCap: Some(14),
    rounds: None,
    repScheme: None,
    scaledParts:
      Some([
        {
          reps: `Cal2((30, 20)),
          weight: (None, None),
          exercise: `SkiErg,
          equipment: None,
        },
        {
          reps: `Meter(250),
          weight: (None, None),
          exercise: `Swim,
          equipment: None,
        },
        {
          reps: `Num(75),
          weight: (None, None),
          exercise: `SingleUnder,
          equipment: Some(`Unbroken),
        },
        {
          reps: `Num(75),
          weight: (None, None),
          exercise: `SingleUnder,
          equipment: Some(`Unbroken),
        },
        {
          reps: `Num(75),
          weight: (None, None),
          exercise: `SingleUnder,
          equipment: Some(`Unbroken),
        },
        {
          reps: `Cal2((30, 20)),
          weight: (None, None),
          exercise: `SkiErg,
          equipment: None,
        },
      ]),
    parts: [
      {
        reps: `Cal2((40, 30)),
        weight: (None, None),
        exercise: `SkiErg,
        equipment: None,
      },
      {
        reps: `Meter(250),
        weight: (None, None),
        exercise: `Swim,
        equipment: None,
      },
      {
        reps: `Num(50),
        weight: (None, None),
        exercise: `DoubleUnderHeavy,
        equipment: Some(`Unbroken),
      },
      {
        reps: `Num(50),
        weight: (None, None),
        exercise: `DoubleUnderHeavy,
        equipment: Some(`Unbroken),
      },
      {
        reps: `Num(50),
        weight: (None, None),
        exercise: `DoubleUnderHeavy,
        equipment: Some(`Unbroken),
      },
      {
        reps: `Cal2((40, 30)),
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
    scaledParts: None,
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
    scaledParts: None,
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
        weight: (Some(`kg(24.0)), Some(`kg(16.0))),
        exercise: `KBS,
        equipment: Some(`Kettlebell),
      },
      {
        reps: `Num(30),
        weight: (Some(`kg(50.0)), Some(`kg(35.0))),
        exercise: `PushPress,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(40),
        weight: (Some(`kg(24.0)), Some(`kg(16.0))),
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
    scaledParts: None,
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
        weight: (Some(`kg(15.0)), Some(`kg(10.0))),
        exercise: `RussianTwist,
        equipment: None,
      },
      {
        reps: `Span((`Num(5), `Num(10))),
        weight: (Some(`kg2(12.0)), Some(`kg2(8.0))),
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
    scaledParts: None,
    externalLink: None,
    description: Some((Some("Rest 3 min between rounds"), None)),
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
        weight: (Some(`kg(9.0)), Some(`kg(6.0))),
        exercise: `WallBall,
        equipment: Some(`WallBall),
      },
    ],
  },
  {
    id: "cf-open-18-2",
    createdAt: "2019-08-20T22:00:00.000Z",
    name: None,
    buyInOut: None,
    wodType: `ForTime,
    category: Some(`Open((18, 2, `Scaled))),
    externalLink: None,
    description:
      Some((
        Some(
          "After all rounds are complete establish a 1-rep-max clean in
                remaining time",
        ),
        None,
      )),
    timeCap: Some(12),
    rounds: None,
    repScheme: Some([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    scaledParts:
      Some([
        {
          reps: `RepScheme,
          weight: (Some(`kg2(15.0)), Some(`kg2(10.0))),
          exercise: `Squat,
          equipment: Some(`Dumbbell),
        },
        {
          reps: `RepScheme,
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `BarFacingBurpee,
          equipment: None,
        },
      ]),
    parts: [
      {
        reps: `RepScheme,
        weight: (Some(`kg2(22.5)), Some(`kg2(15.0))),
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
    scaledParts: None,
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
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
    scaledParts: None,
    description: None,
    externalLink: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(30),
        weight: (Some(`kg(61.0)), Some(`kg(43.0))),
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
    scaledParts: None,
    description: None,
    timeCap: None,
    rounds: Some(3),
    repScheme: None,
    parts: [
      {
        reps: `Num(15),
        weight: (Some(`kg2(15.0)), Some(`kg2(10.0))),
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
        weight: (Some(`kg2cm((15.0, 60.0))), Some(`kg2cm((10.0, 45.0)))),
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
    scaledParts: None,
    description:
      Some((
        Some(
          {j|
Wear a weighted west if available. On the last round, do 15 air squats.

This Firefighter Hero WOD is dedicated to Keithroy Maynard, FDNY, Engine 33, who was killed on September 11, 2001.
          |j},
        ),
        None,
      )),
    timeCap: None,
    rounds: Some(5),
    repScheme: None,
    parts: [
      {
        reps: `Num(44),
        weight: (Some(`cm(60.0)), Some(`cm(45.0))),
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
    scaledParts: None,
    description: None,
    externalLink: None,
    timeCap: None,
    rounds: Some(7),
    repScheme: None,
    parts: [
      {
        reps: `Num(7),
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(7),
        weight: (Some(`kg(40.0)), Some(`kg(30.0))),
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
    scaledParts: None,
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
        weight: (Some(`kg(15.0)), Some(`kg(10.0))),
        exercise: `Lunge,
        equipment: Some(`BulgarianBag),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg2(15.0)), Some(`kg2(10.0))),
        exercise: `GroundToOverhead,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Num(10),
        weight: (Some(`kg2(15.0)), Some(`kg2(10.0))),
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
    scaledParts: None,
    externalLink:
      Some((
        "CrossFit Mayhem",
        "https://www.crossfitmayhem.com/daily-workout-posts/2019/6/16/6172019",
      )),
    description:
      Some((
        Some(
          {j|
Each set EMOM 5 min, then 1 min rest before next EMOM.

* First set (5 reps) light weight, touch and go
* Second set (3 reps) medium weight, touch and go
* Third set (1 rep - E30s) heavy weight
* Last set (5 reps) same as first set
|j},
        ),
        None,
      )),
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
    scaledParts: None,
    category: None,
    buyInOut: None,
    description:
      Some((
        Some(
          {j|
Each set EMOM 5 min, then 1 min rest before next EMOM.

* First set (5 reps) light weight, touch and go
* Second set (3 reps) medium weight, touch and go
* Third set (1 rep - E30s) heavy weight
* Last set (5 reps) same as first set
          |j},
        ),
        None,
      )),
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
    wodType: `AMRAP,
    category: Some(`Wodapalooza(2019)),
    scaledParts:
      Some([
        {
          reps: `Increasing(3),
          weight: (Some(`kg(20.0)), Some(`kg(13.0))),
          exercise: `SnatchHangPower,
          equipment: Some(`Barbell),
        },
        {
          reps: `Increasing(3),
          weight: (Some(`kg(20.0)), Some(`kg(13.0))),
          exercise: `OverheadSquat,
          equipment: Some(`Barbell),
        },
        {
          reps: `Num(30),
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `SingleUnder,
          equipment: Some(`JumpRope),
        },
      ]),
    buyInOut: None,
    externalLink:
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-1/",
      )),
    description:
      Some((
        Some(
          {j|
Add 3 repetitions to each of the barbell movements (3/3/30, 6/6/30, 9/9/30, 12/12/30... etc..) at the conclusion of each round.
          |j},
        ),
        None,
      )),
    timeCap: Some(9),
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Increasing(3),
        weight: (Some(`kg(34.0)), Some(`kg(25.0))),
        exercise: `SnatchHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Increasing(3),
        weight: (Some(`kg(34.0)), Some(`kg(25.0))),
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
  {
    id: "wzaoc192",
    createdAt: "2019-08-30T12:18:15.258Z",
    name: Some("WZAOC 2"),
    wodType: `AMRAP,
    category: Some(`Wodapalooza(2019)),
    scaledParts:
      Some([
        {
          reps: `Num(40),
          weight: (Some(`kg(15.0)), Some(`kg(10.0))),
          exercise: `SnatchAlt,
          equipment: Some(`Dumbbell),
        },
        {
          reps: `Num(40),
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `PullUpJumping,
          equipment: None,
        },
        {
          reps: `Num(30),
          weight: (Some(`kg(15.0)), Some(`kg(10.0))),
          exercise: `Burpee,
          equipment: Some(`Dumbbell),
        },
        {
          reps: `Num(30),
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `RingRow,
          equipment: None,
        },
        {
          reps: `Num(20),
          weight: (Some(`kg(15.0)), Some(`kg(10.0))),
          exercise: `DevilPress,
          equipment: None,
        },
        {
          reps: `Num(20),
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `PullUp,
          equipment: None,
        },
      ]),
    buyInOut: None,
    externalLink:
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-2/",
      )),
    description: None,
    timeCap: Some(16),
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(40),
        weight: (Some(`kg(22.5)), Some(`kg(15.0))),
        exercise: `SnatchAlt,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Num(40),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(30),
        weight: (Some(`kg(22.5)), Some(`kg(15.0))),
        exercise: `Burpee,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `Num(30),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `C2B,
        equipment: None,
      },
      {
        reps: `Num(20),
        weight: (Some(`kg(22.5)), Some(`kg(15.0))),
        exercise: `DevilPress,
        equipment: None,
      },
      {
        reps: `Num(20),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BarMuscleUp,
        equipment: None,
      },
    ],
  },
  {
    id: "wza-oc-19-3",
    createdAt: "2019-09-02T18:28:00.514Z",
    name: Some("WZAOC 3"),
    wodType: `ForTime,
    category: Some(`Wodapalooza(2019)),
    scaledParts:
      Some([
        {
          reps: `Num(12),
          weight: (Some(`kg(34.0)), Some(`kg(25.0))),
          exercise: `Deadlift,
          equipment: Some(`Barbell),
        },
        {
          reps: `Num(9),
          weight: (Some(`kg(34.0)), Some(`kg(25.0))),
          exercise: `CleanHangPower,
          equipment: Some(`Barbell),
        },
        {
          reps: `Num(6),
          weight: (Some(`kg(34.0)), Some(`kg(25.0))),
          exercise: `ShoulderToOverhead,
          equipment: Some(`Barbell),
        },
      ]),
    buyInOut: None,
    externalLink:
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-3/",
      )),
    description:
      Some((
        Some(
          {j|
Every 4 minutes, complete 3 rounds of the exercises. Starting at these weights.

If you complete the three rounds at a given weight within the 4 min window, increase the weight to the next load, add another 4:00 to your time-cap, and immediately begin on the next three rounds.

* Round 1 - 43/30 kg (95/65 lbs)
* Round 2 - 61/43 kg (135/95 lbs)
* Round 3 - 70/48 kg (155/105 lbs)
* Round 4 - 84/59 kg (185/130 lbs)
* Round 5 - 93/66 kg (205/145 lbs) - AMRAP with remaining time
          |j},
        ),
        Some(
          {j|
Every 4 minutes, complete 3 rounds of the exercises. Starting at these weights.

If you complete the three rounds at a given weight within the 4 min window, increase the weight to the next load, add another 4:00 to your time-cap, and immediately begin on the next three rounds.

* Round 1 - 34/25 kg (75/55 lbs)
* Round 2 - 43/30 kg (95/65 lbs)
* Round 3 - 52/36 kg (115/80 lbs)
* Round 4 - 61/43 kg (135/95 lbs)
* Round 5 - 70/48 kg (155/105 lbs) - AMRAP with remaining time

          |j},
        ),
      )),
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(12),
        weight: (Some(`kg(43.0)), Some(`kg(30.0))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(9),
        weight: (Some(`kg(43.0)), Some(`kg(30.0))),
        exercise: `CleanHangPower,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(6),
        weight: (Some(`kg(43.0)), Some(`kg(30.0))),
        exercise: `ShoulderToOverhead,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "wza-oc-19-4",
    createdAt: "2019-09-02T18:21:12.046Z",
    name: Some("WZAOC 4"),
    wodType: `ForTime,
    category: Some(`Wodapalooza(2019)),
    scaledParts:
      Some([
        {
          reps: `Num(100),
          weight: (Some(`kg(6.0)), Some(`kg(4.0))),
          exercise: `WallBall,
          equipment: Some(`WallBall),
        },
        {
          reps: `Num(50),
          weight: (Some(`bodyweight), Some(`bodyweight)),
          exercise: `WeightedButterflySitUp,
          equipment: None,
        },
      ]),
    buyInOut: None,
    externalLink:
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-4/",
      )),
    description:
      Some((
        Some(
          "Perform in any order, until completion of total work. Can be
                broken down or performed in any order.",
        ),
        None,
      )),
    timeCap: Some(20),
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(150),
        weight: (Some(`kg(9.0)), Some(`kg(6.0))),
        exercise: `WallBall,
        equipment: Some(`WallBall),
      },
      {
        reps: `Num(75),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `ToesToBar,
        equipment: None,
      },
    ],
  },
];
