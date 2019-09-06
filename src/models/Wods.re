let wods = [
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=`AMRAP,
    ~timeCap=Some(30),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=`ForTime,
    ~rounds=Some(5),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=`ForTime,
    ~rounds=Some(10),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~name=Some("DT"),
    ~wodType=`ForTime,
    ~category=Some(`Hero),
    ~description=
      Some((
        Some(
          "In honor of US Air Force SSgt Timothy P. Davis, 28, who
    was killed on Feburary, 20 2009 supporting operations in OEF when his vehicle was struck by an IED.",
        ),
        None,
      )),
    ~rounds=Some(5),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~name=Some("Half Murph"),
    ~wodType=`ForTime,
    ~category=Some(`Hero),
    ~description=
      Some((
        Some(
          "In memory of Navy Lieutenant Michael P. Murphy, who was killed in
             Afghanistan June 28, 2005. Murphy was awarded the U.S. military's
             highest decoration, the Medal of Honor, for his actions during the
             War in Afghanistan.",
        ),
        None,
      )),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Chip Through Monday"),
    ~wodType=`ForTime,
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Ski School"),
    ~wodType=`ForTime,
    ~category=Some(`Wodapalooza(2018)),
    ~externalLink=
      Some(("Wodapalooza", "https://wodapalooza.com/workout/ski-school/")),
    ~description=
      Some((
        Some(
          {j|
For every break on jump rope, add 5 cal to last Ski-Erg.

Scaled may exchange singles to 25 dubs.
            |j},
        ),
        None,
      )),
    ~timeCap=Some(14),
    ~scaledParts=
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
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~wodType=`ForTime,
    ~rounds=Some(5),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Waterworks"),
    ~wodType=`ForTime,
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~wodType=`AltEMOM(24),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=`ForTime,
    ~description=Some((Some("Rest 3 min between rounds"), None)),
    ~rounds=Some(2),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=`ForTime,
    ~category=Some(`Open((18, 2, `Scaled))),
    ~description=
      Some((
        Some(
          "After all rounds are complete establish a 1-rep-max clean in
                remaining time",
        ),
        None,
      )),
    ~timeCap=Some(12),
    ~repScheme=Some([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    ~scaledParts=
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
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=`ForTime,
    ~timeCap=Some(6),
    ~repScheme=Some([100, 10, 80, 8, 60, 6, 40, 4, 20, 2]),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-21T22:00:00.000Z",
    ~name=Some("Grace"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~parts=[
      {
        reps: `Num(30),
        weight: (Some(`kg(61.0)), Some(`kg(43.0))),
        exercise: `CleanAndJerk,
        equipment: Some(`Barbell),
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-21T22:00:00.000Z",
    ~wodType=`ForTime,
    ~rounds=Some(3),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-22T22:00:00.000Z",
    ~name=Some("Keithroy Maynard"),
    ~wodType=`ForTime,
    ~category=Some(`Hero),
    ~description=
      Some((
        Some(
          {j|
Wear a weighted west if available. On the last round, do 15 air squats.

This Firefighter Hero WOD is dedicated to Keithroy Maynard, FDNY, Engine 33, who was killed on September 11, 2001.
            |j},
        ),
        None,
      )),
    ~rounds=Some(5),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-24T10:05:54.996Z",
    ~name=Some("7-7-7"),
    ~wodType=`ForTime,
    ~rounds=Some(7),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-24T10:10:43.893Z",
    ~wodType=`AMRAP,
    ~buyInOut=
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
    ~timeCap=Some(8),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:37:11.543Z",
    ~name=Some("190617-Mayhem"),
    ~wodType=`EMOM(23),
    ~externalLink=
      Some((
        "CrossFit Mayhem",
        "https://www.crossfitmayhem.com/daily-workout-posts/2019/6/16/6172019",
      )),
    ~description=
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
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:51:40.140Z",
    ~name=Some("190617-Mayhem with Cleans"),
    ~wodType=`EMOM(23),
    ~description=
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
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:51:40.140Z",
    ~name=Some("WZAOC 1"),
    ~wodType=`AMRAP,
    ~category=Some(`Wodapalooza(2019)),
    ~scaledParts=
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
    ~externalLink=
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-1/",
      )),
    ~description=
      Some((
        Some(
          {j|
Add 3 repetitions to each of the barbell movements (3/3/30, 6/6/30, 9/9/30, 12/12/30... etc..) at the conclusion of each round.
            |j},
        ),
        None,
      )),
    ~timeCap=Some(9),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-30T12:18:15.258Z",
    ~name=Some("WZAOC 2"),
    ~wodType=`AMRAP,
    ~category=Some(`Wodapalooza(2019)),
    ~scaledParts=
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
    ~externalLink=
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-2/",
      )),
    ~timeCap=Some(16),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-02T18:28:00.514Z",
    ~name=Some("WZAOC 3"),
    ~wodType=`ForTime,
    ~category=Some(`Wodapalooza(2019)),
    ~scaledParts=
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
    ~externalLink=
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-3/",
      )),
    ~description=
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
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-02T18:21:12.046Z",
    ~name=Some("WZAOC 4"),
    ~wodType=`ForTime,
    ~category=Some(`Wodapalooza(2019)),
    ~scaledParts=
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
    ~externalLink=
      Some((
        "Wodapalooza",
        "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-4/",
      )),
    ~description=
      Some((
        Some(
          "Perform in any order, until completion of total work. Can be
                broken down or performed in any order.",
        ),
        None,
      )),
    ~timeCap=Some(20),
    ~parts=[
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
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:06:13.922Z",
    ~name=Some("Fran"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
_Fran_ is arguably the most famous of the original six CrossFit "Girls" WODs.
  It was first posted on crossfit.com as the workout of the day for November
  21, 2004, but it was created by CrossFit founder Greg Glassman years
  earlier, in the 1970's, to help him build conditioning as a competitive gymnast.
            |j},
        ),
        None,
      )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      {
        reps: `RepScheme,
        weight: (Some(`kg(43.0)), Some(`kg(30.0))),
        exercise: `Thruster,
        equipment: Some(`Barbell),
      },
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:14:07.486Z",
    ~name=Some("Barbara"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
Time each round, score is total time for all rounds.

_Barbara_, one of CrossFit's first six "Girls" WODs, was first posted on
crossfit.com as the workout of the day for Sunday, July 13, 2003. The original
version allowed 5 minutes rest between sets.
            |j},
        ),
        None,
      )),
    ~rounds=Some(5),
    ~parts=[
      {
        reps: `Num(20),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(30),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(40),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `SitUp,
        equipment: None,
      },
      {
        reps: `Num(50),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
      {
        reps: `Min(3),
        weight: (None, None),
        exercise: `Rest,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:19:42.380Z",
    ~name=Some("Angie"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
Complete all reps of each exercise before moving on to the next.

_Angie_, one of CrossFit's first six "Girls" WODs, was first posted on the CrossFit Main Site as the workout of the day for Saturday, April 16, 2005.
            |j},
        ),
        None,
      )),
    ~parts=[
      {
        reps: `Num(100),
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
        reps: `Num(100),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `SitUp,
        equipment: None,
      },
      {
        reps: `Num(100),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:23:39.000Z",
    ~name=Some("Chelsea"),
    ~wodType=`EMOM(30),
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
If you fall behind the clock, keep going for 30 minutes and see how many rounds you can complete.

If you’ve finished the workout before, this time add 1 rep to each exercise—i.e., 6 pull-ups, 11 push-ups, and 16 squats each minute—and see if you can go the full 30 minutes.

_Chelsea_, one of CrossFit's first six "Girls" WODs, was first posted on crossfit.com as the workout of the day for Sunday, September 7, 2003.
            |j},
        ),
        None,
      )),
    ~parts=[
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(10),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(15),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:00:14.695Z",
    ~name=Some("Diane"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
_Diane_, one of CrossFit's original six "Girls" WODs, was first posted on crossfit.com as the workout of the day for Friday, June 25, 2004.
              |j},
        ),
        None,
      )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      {
        reps: `RepScheme,
        weight: (Some(`kg(100.0)), Some(`kg(70.0))),
        exercise: `Deadlift,
        equipment: None,
      },
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `HandstandPushUp,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:04:01.214Z",
    ~name=Some("Elizabeth"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
_Elizabeth_, one of CrossFit's original six "Girls" WODs. It was first posted on the CrossFit Main Site as the workout of the day for Friday, September 12, 2003.
            |j},
        ),
        None,
      )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      {
        reps: `RepScheme,
        weight: (Some(`kg(60.0)), Some(`kg(43.0))),
        exercise: `CleanSquat,
        equipment: Some(`Barbell),
      },
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `RingDip,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:07:48.979Z",
    ~name=Some("Amanda"),
    ~wodType=`ForTime,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|
_Amanda_ is one of the classic CrossFit "Girl" workouts, but not one of the
  original six from 2003. This workout was added to the list of Girls when it
  was posted as the CrossFit workout of the day on Saturday, July 17, 2010.
              |j},
        ),
        None,
      )),
    ~repScheme=Some([9, 7, 5]),
    ~parts=[
      {
        reps: `RepScheme,
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `MuscleUp,
        equipment: None,
      },
      {
        reps: `RepScheme,
        weight: (Some(`kg(60.0)), Some(`kg(43.0))),
        exercise: `SnatchSquat,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T13:43:41.746Z",
    ~name=Some("Cindy"),
    ~wodType=`AMRAP,
    ~category=Some(`Girl),
    ~description=
      Some((
        Some(
          {j|_Cindy_, typically thought of as one of CrossFit's classic "Girls" workouts, has been around since 2005, but was not actually not named as one of "The Girls" in a 2010 CrossFit Journal article. Despite that, it remains one of the most popular CrossFit workouts.|j},
        ),
        None,
      )),
    ~timeCap=Some(20),
    ~parts=[
      {
        reps: `Num(5),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PullUp,
        equipment: None,
      },
      {
        reps: `Num(10),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(15),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T13:51:00.595Z",
    ~name=Some("The Chief"),
    ~wodType=`AMRAP,
    ~description=
      Some((
        Some(
          {j|
Complete as many rounds as possible in 3 minutes, then rest 1 minute. Start each 3-minute cycle where you left off on the previous cycle. Repeat for a total of 5 cycles. Count total rounds and reps completed.
          |j},
        ),
        None,
      )),
    ~timeCap=Some(3),
    ~rounds=Some(5),
    ~parts=[
      {
        reps: `Num(3),
        weight: (Some(`kg(60.0)), Some(`kg(43.0))),
        exercise: `CleanPower,
        equipment: None,
      },
      {
        reps: `Num(6),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `PushUp,
        equipment: None,
      },
      {
        reps: `Num(9),
        weight: (Some(`bodyweight), Some(`bodyweight)),
        exercise: `AirSquat,
        equipment: None,
      },
    ],
    (),
  ),
];