module Exercise = {
  type t = [
    | `AirSquat
    | `BackwardLunge
    | `BoxJump
    | `Burpee
    | `BurpeeBoxOver
    | `BurpeeOverBar
    | `Clean
    | `Deadlift
    | `DevilPress
    | `HangingKneeRaise
    | `HangPowerClean
    | `KBS
    | `SnatchPower
    | `PullUp
    | `PushJerk
    | `PushPress
    | `PushUp
    | `Row
    | `Run
    | `RussianTwist
    | `SingleUnder
    | `SkiErg
    | `SumoDeadliftHighPull
    | `Thruster
    | `VUps
    | `VUpsSide
    | `WallBall
  ];

  let toString =
    fun
    | `AirSquat => "air squat"
    | `BackwardLunge => "backward lunge"
    | `BoxJump => "box jumps"
    | `Burpee => "burpees"
    | `BurpeeBoxOver => "burpee box overs"
    | `BurpeeOverBar => "burpee over bar"
    | `Clean => "clean"
    | `Deadlift => "deadlift"
    | `DevilPress => "devil press"
    | `HangingKneeRaise => "hanging knee raises"
    | `HangPowerClean => "hang power clean"
    | `KBS => "kettlebell swing"
    | `PullUp => "pull-up"
    | `PushJerk => "push jerk"
    | `PushPress => "push press"
    | `PushUp => "push-up"
    | `Row => "row"
    | `Run => "run"
    | `RussianTwist => "russian twist"
    | `SingleUnder => "single unders"
    | `SkiErg => "SkiErg"
    | `SnatchPower => "power snatch"
    | `SumoDeadliftHighPull => "sumo deadlift high pull"
    | `Thruster => "thrusters"
    | `VUps => "v-ups"
    | `VUpsSide => "side v-ups"
    | `WallBall => "wall balls";
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
  type t = [ | `Three(int, int, int)];
};

type t = {
  category: option(Category.t),
  description: option(string),
  id: string,
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
    category: None,
    description: None,
    name: None,
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
    category: None,
    description: None,
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
    name: None,
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
    name: Some("DT"),
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
        exercise: `HangPowerClean,
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
    name: Some("Half Murph"),
    wodType: `ForTime,
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
    name: Some("Chip Through Monday"),
    wodType: `ForTime,
    category: None,
    description: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BurpeeOverBar,
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
        exercise: `BurpeeOverBar,
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
        exercise: `BurpeeOverBar,
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
        exercise: `BurpeeOverBar,
        equipment: None,
      },
      {
        reps: `Num(25),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `HangPowerClean,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `BurpeeOverBar,
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
        exercise: `BurpeeOverBar,
        equipment: None,
      },
    ],
  },
  {
    id: "ski-school",
    name: Some("Ski School"),
    wodType: `ForTime,
    category: Some(`Wodapalooza(2019)),
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
    name: None,
    wodType: `ForTime,
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
    name: Some("Waterworks"),
    wodType: `ForTime,
    category: None,
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
    id: "594ca204-91cd-46b3-837b-0ec5f954bbe2",
    name: None,
    wodType: `ForTime,
    category: None,
    description: None,
    timeCap: None,
    rounds: None,
    repScheme: None,
    parts: [
      {
        reps: `Num(100),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(10),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(80),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(8),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(60),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(6),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(40),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(4),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(20),
        weight: (None, None),
        exercise: `SingleUnder,
        equipment: None,
      },
      {
        reps: `Num(2),
        weight: (Some(`kg(40)), Some(`kg(30))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "da5ae974-deeb-4205-a80b-1ad2529459da",
    name: None,
    wodType: `AltEMOM(24),
    category: None,
    description: None,
    timeCap: None,
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
    name: None,
    wodType: `ForTime,
    category: None,
    description: Some("Rest 3 min between rounds"),
    timeCap: None,
    rounds: Some(2),
    repScheme: Some(`Three((21, 15, 9))),
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
];
