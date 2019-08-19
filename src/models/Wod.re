module WodType = {
  type t = [ | `AMRAP | `EMOM | `ForTime];

  let toString =
    fun
    | `ForTime => "For time"
    | `EMOM => "EMOM"
    | `AMRAP => "AMRAP";
};

module Weight = {
  type t = [ | `Kg(int) | `Kg2(int) | `Bodyweight | `Cm(int)];
};

module ExerciseUnit = {
  type t = [ | `Meter(int) | `OneSide(int, int) | `Num(int) | `Cal(int)];
};

module Category = {
  type t = [ | `Hero | `Girl];
};

module Equipment = {
  type t = [ | `Barbell | `Dumbbell | `Kettlebell | `WallBall | `BulgarianBag];

  let toString =
    fun
    | `Barbell => "Barbell"
    | `Dumbbell => "DB"
    | `Kettlebell => "KB"
    | `WallBall => "medicine ball"
    | `BulgarianBag => "bulgarian bag";
};

module Exercise = {
  type t = [
    | `AirSquat
    | `BackwardLunge
    | `BoxJumps
    | `Clean
    | `Deadlift
    | `DevilPress
    | `HangPowerClean
    | `Row
    | `Run
    | `PullUp
    | `PushJerk
    | `PushPress
    | `PushUp
    | `VUps
    | `KBS
    | `WB
  ];

  let toString =
    fun
    | `AirSquat => "air squat"
    | `BackwardLunge => "backward lunge"
    | `BoxJumps => "box jumps"
    | `Clean => "clean"
    | `Deadlift => "deadlift"
    | `DevilPress => "devil press"
    | `HangPowerClean => "hang power clean"
    | `KBS => "kettlebell swing"
    | `PullUp => "pull-up"
    | `PushJerk => "push jerk"
    | `PushPress => "push press"
    | `PushUp => "push-up"
    | `Row => "row"
    | `Run => "run"
    | `VUps => "V-ups"
    | `WB => "wall balls";
};

module WodPart = {
  type t = {
    weight: (option(Weight.t), option(Weight.t)),
    reps: ExerciseUnit.t,
    exercise: Exercise.t,
    equipment: option(Equipment.t),
  };
};

type t = {
  category: option(Category.t),
  id: string,
  name: option(string),
  wodType: WodType.t,
  timeCap: option(int),
  rounds: option(int),
  parts: list(WodPart.t),
};

let wods = [
  {
    id: "dfa983fb-1fdb-4b67-8b8c-a15184798dc4",
    category: None,
    name: None,
    wodType: `AMRAP,
    timeCap: Some(30),
    rounds: None,
    parts: [
      {
        reps: `Meter(500),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`Kg(20)), Some(`Kg(15))),
        exercise: `PushPress,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`Kg2(15)), Some(`Kg2(12))),
        exercise: `BackwardLunge,
        equipment: Some(`Dumbbell),
      },
      {
        reps: `OneSide((5, 5)),
        weight: (Some(`Kg(16)), Some(`Kg(12))),
        exercise: `KBS,
        equipment: Some(`Kettlebell),
      },
      {
        reps: `Num(10),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `VUps,
        equipment: None,
      },
    ],
  },
  {
    id: "d2b07e7e-a1c1-487e-ad5a-ec9dd89d5fd4",
    name: None,
    category: None,
    wodType: `ForTime,
    timeCap: None,
    rounds: Some(5),
    parts: [
      {
        reps: `Num(10),
        weight: (Some(`Kg(9)), Some(`Kg(6))),
        exercise: `WB,
        equipment: Some(`WallBall),
      },
      {
        reps: `Num(10),
        weight: (Some(`Kg(15)), Some(`Kg(12))),
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
    timeCap: None,
    rounds: Some(10),
    parts: [
      {
        reps: `Cal(9),
        weight: (None, None),
        exercise: `Row,
        equipment: None,
      },
      {
        reps: `Num(6),
        weight: (Some(`Cm(60)), Some(`Cm(45))),
        exercise: `BoxJumps,
        equipment: None,
      },
      {
        reps: `Num(3),
        weight: (Some(`Kg(15)), Some(`Kg(10))),
        exercise: `DevilPress,
        equipment: Some(`Dumbbell),
      },
    ],
  },
  {
    id: "DT",
    name: Some("DT"),
    wodType: `ForTime,
    category: Some(`Hero),
    timeCap: None,
    rounds: Some(5),
    parts: [
      {
        reps: `Num(12),
        weight: (Some(`Kg(70)), Some(`Kg(45))),
        exercise: `Deadlift,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(9),
        weight: (Some(`Kg(70)), Some(`Kg(45))),
        exercise: `HangPowerClean,
        equipment: Some(`Barbell),
      },
      {
        reps: `Num(6),
        weight: (Some(`Kg(70)), Some(`Kg(45))),
        exercise: `PushJerk,
        equipment: Some(`Barbell),
      },
    ],
  },
  {
    id: "HalfMurph",
    name: Some("Half Murph"),
    wodType: `ForTime,
    category: Some(`Hero),
    timeCap: None,
    rounds: None,
    parts: [
      {
        reps: `Meter(800),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `Run,
        equipment: None,
      },
      {
        reps: `Num(50),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(100),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(150),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
      {
        reps: `Meter(800),
        weight: (Some(`Bodyweight), Some(`Bodyweight)),
        exercise: `Run,
        equipment: None,
      },
    ],
  },
];
