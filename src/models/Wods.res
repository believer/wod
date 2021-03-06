open WodPart

let wods = [
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=#AMRAP,
    ~timeCap=Some(30),
    ~parts=[
      make(~reps=#Meter(500), ~exercise=#Row, ()),
      make(
        ~reps=#OneSide((5, 5)),
        ~weight=(Some(#kg(20.0)), Some(#kg(15.0))),
        ~exercise=#PushPress,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#OneSide((5, 5)),
        ~weight=(Some(#kg2(15.0)), Some(#kg2(12.0))),
        ~exercise=#BackwardLunge,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#OneSide((5, 5)),
        ~weight=(Some(#kg(16.0)), Some(#kg(12.0))),
        ~exercise=#Swing,
        ~equipment=Some(Kettlebell),
        (),
      ),
      make(~reps=#Num(10), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#VUps, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=#ForTime,
    ~rounds=Some(5),
    ~parts=[
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(9.0)), Some(#kg(6.0))),
        ~exercise=#WallBall,
        ~equipment=Some(WallBall),
        (),
      ),
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(15.0)), Some(#kg(12.0))),
        ~exercise=#Clean,
        ~equipment=Some(BulgarianBag),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~wodType=#ForTime,
    ~rounds=Some(10),
    ~parts=[
      make(~reps=#Cal(9), ~weight=(None, None), ~exercise=#Row, ()),
      make(~reps=#Num(6), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(
        ~reps=#Num(3),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#DevilPress,
        ~equipment=Some(Dumbbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~name=Some("DT"),
    ~wodType=#ForTime,
    ~category=Some(#Hero),
    ~description=Some((
      Some("In honor of US Air Force SSgt Timothy P. Davis, 28, who
    was killed on Feburary, 20 2009 supporting operations in OEF when his vehicle was struck by an IED."),
      None,
    )),
    ~rounds=Some(5),
    ~parts=[
      make(
        ~reps=#Num(12),
        ~weight=(Some(#kg(70.0)), Some(#kg(47.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(70.0)), Some(#kg(47.0))),
        ~exercise=#CleanHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(6),
        ~weight=(Some(#kg(70.0)), Some(#kg(47.0))),
        ~exercise=#PushJerk,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-18T22:00:00.000Z",
    ~name=Some("Half Murph"),
    ~wodType=#ForTime,
    ~category=Some(#Hero),
    ~description=Some((
      Some("In memory of Navy Lieutenant Michael P. Murphy, who was killed in
             Afghanistan June 28, 2005. Murphy was awarded the U.S. military's
             highest decoration, the Medal of Honor, for his actions during the
             War in Afghanistan."),
      None,
    )),
    ~parts=[
      make(~reps=#Meter(800), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#Run, ()),
      make(~reps=#Num(50), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(~reps=#Num(100), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(
        ~reps=#Num(150),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#AirSquat,
        (),
      ),
      make(~reps=#Meter(800), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#Run, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Chip Through Monday"),
    ~wodType=#ForTime,
    ~parts=[
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        ~equipment=None,
        (),
      ),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#SumoDeadliftHighPull,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
      make(
        ~reps=#Num(20),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#PushPress,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
      make(
        ~reps=#Num(25),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#CleanHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Ski School"),
    ~wodType=#ForTime,
    ~category=Some(#Wodapalooza(2018)),
    ~externalLink=Some(("Wodapalooza", "https://wodapalooza.com/workout/ski-school/")),
    ~description=Some((
      Some(j`
For every break on jump rope, add 5 cal to last Ski-Erg.

Scaled may exchange singles to 25 dubs.
          `),
      None,
    )),
    ~timeCap=Some(14),
    ~scaledParts=Some([
      make(~reps=#Cal2((30, 20)), ~exercise=#SkiErg, ()),
      make(~reps=#Meter(250), ~exercise=#Swim, ()),
      make(~reps=#Num(75), ~exercise=#SingleUnder, ~equipment=Some(Unbroken), ()),
      make(~reps=#Num(75), ~exercise=#SingleUnder, ~equipment=Some(Unbroken), ()),
      make(~reps=#Num(75), ~exercise=#SingleUnder, ~equipment=Some(Unbroken), ()),
      make(~reps=#Cal2((30, 20)), ~exercise=#SkiErg, ()),
    ]),
    ~parts=[
      make(~reps=#Cal2((40, 30)), ~exercise=#SkiErg, ()),
      make(~reps=#Meter(250), ~exercise=#Swim, ()),
      make(~reps=#Num(50), ~exercise=#DoubleUnderHeavy, ~equipment=Some(Unbroken), ()),
      make(~reps=#Num(50), ~exercise=#DoubleUnderHeavy, ~equipment=Some(Unbroken), ()),
      make(~reps=#Num(50), ~exercise=#DoubleUnderHeavy, ~equipment=Some(Unbroken), ()),
      make(~reps=#Cal2((40, 30)), ~exercise=#SkiErg, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~wodType=#ForTime,
    ~rounds=Some(5),
    ~parts=[
      make(~reps=#Num(100), ~exercise=#SingleUnder, ()),
      make(
        ~reps=#Num(5),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#SnatchPower,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~name=Some("Waterworks"),
    ~wodType=#ForTime,
    ~parts=[
      make(~reps=#Cal2((50, 35)), ~exercise=#Row, ()),
      make(
        ~reps=#Num(40),
        ~weight=(Some(#kg(24.0)), Some(#kg(16.0))),
        ~exercise=#Swing,
        ~equipment=Some(Kettlebell),
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#kg(50.0)), Some(#kg(35.0))),
        ~exercise=#PushPress,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(40),
        ~weight=(Some(#kg(24.0)), Some(#kg(16.0))),
        ~exercise=#Swing,
        ~equipment=Some(Kettlebell),
        (),
      ),
      make(~reps=#Cal2((50, 35)), ~exercise=#Row, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-19T22:00:00.000Z",
    ~wodType=#AltEMOM(24),
    ~parts=[
      make(
        ~reps=#Span((#Num(8), #Num(12))),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#HangingKneeRaise,
        (),
      ),
      make(~reps=#Span((#Cal(6), #Cal(14))), ~exercise=#SkiErg, ()),
      make(
        ~reps=#Span((#OneSide((8, 8)), #OneSide((14, 14)))),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#RussianTwist,
        (),
      ),
      make(
        ~reps=#Span((#Num(5), #Num(10))),
        ~weight=(Some(#kg2(12.0)), Some(#kg2(8.0))),
        ~exercise=#BurpeeBoxOver,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Span((#OneSide((6, 6)), #OneSide((9, 9)))),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#VUpsSide,
        (),
      ),
      make(~reps=#Span((#Cal(6), #Cal(14))), ~exercise=#Row, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=#ForTime,
    ~description=Some((Some("Rest 3 min between rounds"), None)),
    ~rounds=Some(2),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      make(~reps=#RepScheme, ~exercise=#SkiErg, ()),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(9.0)), Some(#kg(6.0))),
        ~exercise=#WallBall,
        ~equipment=Some(WallBall),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Open 18.2"),
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(18)),
    ~description=Some((
      Some("After all rounds are complete establish a 1-rep-max clean in
                remaining time"),
      None,
    )),
    ~externalLink=Some((
      "CrossFit Games Open 18.2",
      "https://games.crossfit.com/workouts/open/2018/2",
    )),
    ~timeCap=Some(12),
    ~repScheme=Some([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    ~scaledParts=Some([
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg2(15.0)), Some(#kg2(10.0))),
        ~exercise=#Squat,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
    ]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg2(22.5)), Some(#kg2(15.0))),
        ~exercise=#Squat,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarFacingBurpee,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-20T22:00:00.000Z",
    ~wodType=#ForTime,
    ~timeCap=Some(6),
    ~repScheme=Some([100, 10, 80, 8, 60, 6, 40, 4, 20, 2]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#SingleUnder,
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#PushPress,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-21T22:00:00.000Z",
    ~name=Some("Grace"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~parts=[
      make(
        ~reps=#Num(30),
        ~weight=(Some(#kg(61.0)), Some(#kg(43.0))),
        ~exercise=#CleanAndJerk,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-21T22:00:00.000Z",
    ~wodType=#ForTime,
    ~rounds=Some(3),
    ~parts=[
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg2(15.0)), Some(#kg2(10.0))),
        ~exercise=#PushJerk,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#SingleUnder,
        (),
      ),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg2cm((15.0, 60.0))), Some(#kg2cm((10.0, 45.0)))),
        ~exercise=#WeightedStepUp,
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#SingleUnder,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-22T22:00:00.000Z",
    ~name=Some("Keithroy Maynard"),
    ~wodType=#ForTime,
    ~category=Some(#Hero),
    ~description=Some((
      Some(j`
Wear a weighted west if available. On the last round, do 15 air squats.

This Firefighter Hero WOD is dedicated to Keithroy Maynard, FDNY, Engine 33, who was killed on September 11, 2001.
            `),
      None,
    )),
    ~rounds=Some(5),
    ~parts=[
      make(~reps=#Num(44), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxStepUp, ()),
      make(~reps=#Num(12), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(12), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#AirSquat, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-24T10:05:54.996Z",
    ~name=Some("7-7-7"),
    ~wodType=#ForTime,
    ~rounds=Some(7),
    ~parts=[
      make(
        ~reps=#Num(7),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(7),
        ~weight=(Some(#kg(40.0)), Some(#kg(30.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(7), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#Burpee, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-24T10:10:43.893Z",
    ~wodType=#AMRAP,
    ~buyInOut=Some((
      Some(make(~reps=#Meter(500), ~exercise=#Row, ())),
      Some(make(~reps=#Meter(500), ~exercise=#SkiErg, ())),
    )),
    ~timeCap=Some(8),
    ~parts=[
      make(
        ~reps=#OneSide((5, 5)),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#Lunge,
        ~equipment=Some(BulgarianBag),
        (),
      ),
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg2(15.0)), Some(#kg2(10.0))),
        ~exercise=#GroundToOverhead,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg2(15.0)), Some(#kg2(10.0))),
        ~exercise=#BentOverRow,
        ~equipment=Some(Dumbbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:37:11.543Z",
    ~name=Some("190617"),
    ~wodType=#EMOM(23),
    ~category=Some(#Mayhem),
    ~externalLink=Some((
      "CrossFit Mayhem",
      "https://www.crossfitmayhem.com/daily-workout-posts/2019/6/16/6172019",
    )),
    ~description=Some((
      Some(j`
Each set EMOM 5 min, then 1 min rest before next EMOM.

* First set (5 reps) light weight, touch and go
* Second set (3 reps) medium weight, touch and go
* Third set (1 rep - E30s) heavy weight
* Last set (5 reps) same as first set
            `),
      None,
    )),
    ~parts=[
      make(~reps=#Num(5), ~exercise=#SnatchPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(~reps=#Num(3), ~exercise=#SnatchPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(~reps=#Num(1), ~exercise=#SnatchPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(
        ~reps=#Num(5),
        ~weight=(None, None),
        ~exercise=#SnatchPower,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:51:40.140Z",
    ~name=Some("190617 (clean version)"),
    ~wodType=#EMOM(23),
    ~category=Some(#Mayhem),
    ~description=Some((
      Some(j`
Each set EMOM 5 min, then 1 min rest before next EMOM.

* First set (5 reps) light weight, touch and go
* Second set (3 reps) medium weight, touch and go
* Third set (1 rep - E30s) heavy weight
* Last set (5 reps) same as first set
            `),
      None,
    )),
    ~parts=[
      make(~reps=#Num(5), ~exercise=#CleanPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(~reps=#Num(3), ~exercise=#CleanPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(~reps=#Num(1), ~exercise=#CleanPower, ~equipment=Some(Barbell), ()),
      rest(1),
      make(~reps=#Num(5), ~exercise=#CleanPower, ~equipment=Some(Barbell), ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-27T16:51:40.140Z",
    ~name=Some("WZAOC 1"),
    ~wodType=#AMRAP,
    ~category=Some(#Wodapalooza(2019)),
    ~scaledParts=Some([
      make(
        ~reps=#Increasing(3),
        ~weight=(Some(#kg(20.0)), Some(#kg(13.0))),
        ~exercise=#SnatchHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Increasing(3),
        ~weight=(Some(#kg(20.0)), Some(#kg(13.0))),
        ~exercise=#OverheadSquat,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#SingleUnder,
        ~equipment=Some(JumpRope),
        (),
      ),
    ]),
    ~externalLink=Some(("Wodapalooza", "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-1/")),
    ~description=Some((
      Some(j`
Add 3 repetitions to each of the barbell movements (3/3/30, 6/6/30, 9/9/30, 12/12/30... etc..) at the conclusion of each round.
            `),
      None,
    )),
    ~timeCap=Some(9),
    ~parts=[
      make(
        ~reps=#Increasing(3),
        ~weight=(Some(#kg(34.0)), Some(#kg(25.0))),
        ~exercise=#SnatchHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Increasing(3),
        ~weight=(Some(#kg(34.0)), Some(#kg(25.0))),
        ~exercise=#OverheadSquat,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#DoubleUnder,
        ~equipment=Some(JumpRope),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-08-30T12:18:15.258Z",
    ~name=Some("WZAOC 2"),
    ~wodType=#AMRAP,
    ~category=Some(#Wodapalooza(2019)),
    ~scaledParts=Some([
      make(
        ~reps=#Num(40),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#SnatchAlt,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(40),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#PullUpJumping,
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#Burpee,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(30), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#RingRow, ()),
      make(
        ~reps=#Num(20),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#DevilPress,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(20), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
    ]),
    ~externalLink=Some(("Wodapalooza", "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-2/")),
    ~timeCap=Some(16),
    ~parts=[
      make(
        ~reps=#Num(40),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#SnatchAlt,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(40), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#Burpee,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(30),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#ChestToBar,
        (),
      ),
      make(
        ~reps=#Num(20),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#DevilPress,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(20),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BarMuscleUp,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-02T18:28:00.514Z",
    ~name=Some("WZAOC 3"),
    ~wodType=#ForTime,
    ~category=Some(#Wodapalooza(2019)),
    ~scaledParts=Some([
      make(
        ~reps=#Num(12),
        ~weight=(Some(#kg(34.0)), Some(#kg(25.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(34.0)), Some(#kg(25.0))),
        ~exercise=#CleanHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(6),
        ~weight=(Some(#kg(34.0)), Some(#kg(25.0))),
        ~exercise=#ShoulderToOverhead,
        ~equipment=Some(Barbell),
        (),
      ),
    ]),
    ~externalLink=Some(("Wodapalooza", "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-3/")),
    ~description=Some((
      Some(j`
Every 4 minutes, complete 3 rounds of the exercises. Starting at these weights.

If you complete the three rounds at a given weight within the 4 min window, increase the weight to the next load, add another 4:00 to your time-cap, and immediately begin on the next three rounds.

* Round 1 - 43/30 kg (95/65 lbs)
* Round 2 - 61/43 kg (135/95 lbs)
* Round 3 - 70/48 kg (155/105 lbs)
* Round 4 - 84/59 kg (185/130 lbs)
* Round 5 - 93/66 kg (205/145 lbs) - AMRAP with remaining time
            `),
      Some(j`
Every 4 minutes, complete 3 rounds of the exercises. Starting at these weights.

If you complete the three rounds at a given weight within the 4 min window, increase the weight to the next load, add another 4:00 to your time-cap, and immediately begin on the next three rounds.

* Round 1 - 34/25 kg (75/55 lbs)
* Round 2 - 43/30 kg (95/65 lbs)
* Round 3 - 52/36 kg (115/80 lbs)
* Round 4 - 61/43 kg (135/95 lbs)
* Round 5 - 70/48 kg (155/105 lbs) - AMRAP with remaining time
            `),
    )),
    ~parts=[
      make(
        ~reps=#Num(12),
        ~weight=(Some(#kg(43.0)), Some(#kg(30.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(43.0)), Some(#kg(30.0))),
        ~exercise=#CleanHangPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#Num(6),
        ~weight=(Some(#kg(43.0)), Some(#kg(30.0))),
        ~exercise=#ShoulderToOverhead,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-02T18:21:12.046Z",
    ~name=Some("WZAOC 4"),
    ~wodType=#ForTime,
    ~category=Some(#Wodapalooza(2019)),
    ~scaledParts=Some([
      make(
        ~reps=#Num(100),
        ~weight=(Some(#kg(6.0)), Some(#kg(4.0))),
        ~exercise=#WallBall,
        ~equipment=Some(WallBall),
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#WeightedButterflySitUp,
        ~equipment=Some(WallBall),
        (),
      ),
    ]),
    ~externalLink=Some(("Wodapalooza", "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-4/")),
    ~description=Some((
      Some("Perform in any order, until completion of total work. Can be
                broken down or performed in any order."),
      None,
    )),
    ~timeCap=Some(20),
    ~parts=[
      make(
        ~reps=#Num(150),
        ~weight=(Some(#kg(9.0)), Some(#kg(6.0))),
        ~exercise=#WallBall,
        ~equipment=Some(WallBall),
        (),
      ),
      make(
        ~reps=#Num(75),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#ToesToBar,
        ~equipment=None,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:06:13.922Z",
    ~name=Some("Fran"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
_Fran_ is arguably the most famous of the original six CrossFit "Girls" WODs.
  It was first posted on crossfit.com as the workout of the day for November
  21, 2004, but it was created by CrossFit founder Greg Glassman years
  earlier, in the 1970's, to help him build conditioning as a competitive gymnast.
            `),
      None,
    )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(43.0)), Some(#kg(30.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#RepScheme, ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:14:07.486Z",
    ~name=Some("Barbara"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
Time each round, score is total time for all rounds.

_Barbara_, one of CrossFit's first six "Girls" WODs, was first posted on
crossfit.com as the workout of the day for Sunday, July 13, 2003. The original
version allowed 5 minutes rest between sets.
            `),
      None,
    )),
    ~rounds=Some(5),
    ~parts=[
      make(~reps=#Num(20), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(~reps=#Num(30), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(40), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#SitUp, ()),
      make(~reps=#Num(50), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#AirSquat, ()),
      rest(3),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:19:42.380Z",
    ~name=Some("Angie"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
Complete all reps of each exercise before moving on to the next.

_Angie_, one of CrossFit's first six "Girls" WODs, was first posted on the CrossFit Main Site as the workout of the day for Saturday, April 16, 2005.
            `),
      None,
    )),
    ~parts=[
      make(~reps=#Num(100), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(~reps=#Num(100), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(100), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#SitUp, ()),
      make(
        ~reps=#Num(100),
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#AirSquat,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T06:23:39.000Z",
    ~name=Some("Chelsea"),
    ~wodType=#EMOM(30),
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
If you fall behind the clock, keep going for 30 minutes and see how many rounds you can complete.

If you’ve finished the workout before, this time add 1 rep to each exercise—i.e., 6 pull-ups, 11 push-ups, and 16 squats each minute—and see if you can go the full 30 minutes.

_Chelsea_, one of CrossFit's first six "Girls" WODs, was first posted on crossfit.com as the workout of the day for Sunday, September 7, 2003.
            `),
      None,
    )),
    ~parts=[
      make(~reps=#Num(5), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(~reps=#Num(10), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(15), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#AirSquat, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:00:14.695Z",
    ~name=Some("Diane"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
_Diane_, one of CrossFit's original six "Girls" WODs, was first posted on crossfit.com as the workout of the day for Friday, June 25, 2004.
              `),
      None,
    )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(100.0)), Some(#kg(70.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#HandstandPushUp,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:04:01.214Z",
    ~name=Some("Elizabeth"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
_Elizabeth_, one of CrossFit's original six "Girls" WODs. It was first posted on the CrossFit Main Site as the workout of the day for Friday, September 12, 2003.
            `),
      None,
    )),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(60.0)), Some(#kg(43.0))),
        ~exercise=#CleanSquat,
        ~equipment=Some(Barbell),
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#RingDip,
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T08:07:48.979Z",
    ~name=Some("Amanda"),
    ~wodType=#ForTime,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`
_Amanda_ is one of the classic CrossFit "Girl" workouts, but not one of the
  original six from 2003. This workout was added to the list of Girls when it
  was posted as the CrossFit workout of the day on Saturday, July 17, 2010.
              `),
      None,
    )),
    ~repScheme=Some([9, 7, 5]),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#MuscleUp,
        (),
      ),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(60.0)), Some(#kg(43.0))),
        ~exercise=#SnatchSquat,
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T13:43:41.746Z",
    ~name=Some("Cindy"),
    ~wodType=#AMRAP,
    ~category=Some(#Girl),
    ~description=Some((
      Some(j`_Cindy_, typically thought of as one of CrossFit's classic "Girls" workouts, has been around since 2005, but was not actually not named as one of "The Girls" in a 2010 CrossFit Journal article. Despite that, it remains one of the most popular CrossFit workouts.`),
      None,
    )),
    ~timeCap=Some(20),
    ~parts=[
      make(~reps=#Num(5), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PullUp, ()),
      make(~reps=#Num(10), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(15), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#AirSquat, ()),
    ],
    (),
  ),
  Wod.make(
    ~createdAt="2019-09-06T13:51:00.595Z",
    ~name=Some("The Chief"),
    ~wodType=#AMRAP,
    ~description=Some((
      Some(j`
Complete as many rounds as possible in 3 minutes, then rest 1 minute. Start each 3-minute cycle where you left off on the previous cycle. Repeat for a total of 5 cycles. Count total rounds and reps completed.
          `),
      None,
    )),
    ~timeCap=Some(3),
    ~rounds=Some(5),
    ~parts=[
      make(
        ~reps=#Num(3),
        ~weight=(Some(#kg(60.0)), Some(#kg(43.0))),
        ~exercise=#CleanPower,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(6), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#PushUp, ()),
      make(~reps=#Num(9), ~weight=(Some(#bodyweight), Some(#bodyweight)), ~exercise=#AirSquat, ()),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Devil in the Row"),
    ~createdAt="2019-09-11T17:39:15.752Z",
    ~wodType=#ForTime,
    ~description=Some((
      Some("Perfect pacing practice, try to keep the same pace through all ten rounds."),
      None,
    )),
    ~rounds=Some(10),
    ~timeCap=Some(20),
    ~parts=[
      make(~reps=#Cal2((9, 7)), ~exercise=#Row, ()),
      make(~reps=#Num(6), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(3), ~weight=(Some(#kg(15.0)), Some(#kg(10.0))), ~exercise=#DevilPress, ()),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("WZAOC 5 & 6"),
    ~createdAt="2019-09-17T10:49:31.034Z",
    ~wodType=#ForTime,
    ~category=Some(#Wodapalooza(2019)),
    ~externalLink=Some((
      "Wodapalooza",
      "https://wodapalooza.com/workout/2019-2020-indy-oc-wod-5-6/",
    )),
    ~description=Some((
      Some(j`
            If not completed within 12 minutes, continue to workout 6.

            **Workout 6**

            _With remaining time of 15:00_

            1 RM Clean and Jerk
          `),
      None,
    )),
    ~timeCap=Some(15),
    ~repScheme=Some([21, 15, 9]),
    ~parts=[
      make(~reps=#RepScheme, ~weight=(Some(#kg(43.0)), Some(#kg(30.0))), ~exercise=#Thruster, ()),
      make(~reps=#RepScheme, ~exercise=#Row, ()),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BurpeeOverRower,
        (),
      ),
    ],
    ~scaledParts=Some([
      make(~reps=#RepScheme, ~weight=(Some(#kg(30.0)), Some(#kg(20.0))), ~exercise=#Thruster, ()),
      make(~reps=#RepScheme, ~exercise=#Row, ()),
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#bodyweight), Some(#bodyweight)),
        ~exercise=#BurpeeOverRower,
        (),
      ),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Monday Push and Pull"),
    ~createdAt="2019-09-17T12:37:29.496Z",
    ~wodType=#AMRAP,
    ~timeCap=Some(8),
    ~parts=[
      make(~reps=#Cal2((8, 10)), ~exercise=#Row, ()),
      make(
        ~reps=#Num(8),
        ~weight=(Some(#kg(12.5)), Some(#kg(10.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Dumbbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Clean and front squat"),
    ~createdAt="2019-09-24T11:39:35.229Z",
    ~category=Some(#Strength),
    ~description=Some((
      Some(j`Start out lighter and if possible increase weights in the later
          sets. Hook grip on all pulling. Release in rack. Calm start but accelerate towards full extension and slight touch on middle of thighs. Snappy rack and landing. Maybe a "deep power landing".`),
      None,
    )),
    ~wodType=#EMOM(12),
    ~parts=[
      make(~reps=#Num(1), ~exercise=#CleanHighPull, ()),
      make(~reps=#Num(1), ~exercise=#CleanPower, ()),
      make(~reps=#Num(1), ~exercise=#FrontSquat, ()),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Dip squat and split jerk"),
    ~createdAt="2019-09-24T11:48:04.553Z",
    ~category=Some(#Strength),
    ~description=Some((
      Some(j`Solid rack and firmly planted feet in jerk dip squat, which is basically a shallow front squat. Split jerk is with focus on timing and precision.`),
      None,
    )),
    ~wodType=#E90(12),
    ~parts=[
      make(~reps=#Num(2), ~exercise=#JerkDipSquat, ()),
      make(~reps=#Num(2), ~exercise=#SplitJerk, ()),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Ski, jump and snatch"),
    ~createdAt="2019-09-24T12:24:42.300Z",
    ~wodType=#ForTime,
    ~rounds=Some(5),
    ~timeCap=Some(15),
    ~parts=[
      make(~reps=#Cal2((10, 8)), ~exercise=#SkiErg, ()),
      make(~reps=#Num(100), ~exercise=#SingleUnder, ()),
      make(
        ~reps=#OneSide((5, 5)),
        ~exercise=#SnatchMuscle,
        ~weight=(Some(#kg(20.0)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Dead ski swings"),
    ~createdAt="2019-09-24T12:30:05.577Z",
    ~wodType=#ForTime,
    ~rounds=Some(10),
    ~timeCap=Some(20),
    ~parts=[
      make(~reps=#Cal2((10, 8)), ~exercise=#SkiErg, ()),
      make(
        ~reps=#Num(5),
        ~exercise=#Deadlift,
        ~weight=(Some(#kg2(32.0)), Some(#kg2(24.0))),
        ~equipment=Some(Kettlebell),
        (),
      ),
      make(
        ~reps=#Num(10),
        ~exercise=#Swing,
        ~weight=(Some(#kg(24.0)), Some(#kg(16.0))),
        ~equipment=Some(Kettlebell),
        (),
      ),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Open 19.1"),
    ~createdAt="2019-10-21T06:08:09.700Z",
    ~wodType=#AMRAP,
    ~category=Some(#Open(19)),
    ~timeCap=Some(15),
    ~externalLink=Some((
      "CrossFit Games Open 19.1",
      "https://games.crossfit.com/workouts/open/2019/1",
    )),
    ~parts=[
      make(~reps=#Num(19), ~weight=(Some(#kg(9.0)), Some(#kg(6.0))), ~exercise=#WallBall, ()),
      make(~reps=#Cal(19), ~exercise=#Row, ()),
    ],
    ~scaledParts=Some([
      make(~reps=#Num(19), ~weight=(Some(#kg(6.0)), Some(#kg(4.0))), ~exercise=#WallBall, ()),
      make(~reps=#Cal(19), ~exercise=#Row, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 19.2"),
    ~createdAt="2019-10-21T06:10:50.847Z",
    ~wodType=#AMRAP,
    ~category=Some(#Open(19)),
    ~timeCap=Some(20),
    ~externalLink=Some((
      "CrossFit Games Open 19.2",
      "https://games.crossfit.com/workouts/open/2019/2",
    )),
    ~description=Some((
      Some(j`
Beginning on an 8-minute clock
If completed before 8 minutes, add 4 minutes to the clock and proceed to:

* 25 toes-to-bars
* 50 double-unders
* 11 squat cleans, 102/65 kg (225/145 lbs)

If completed before 12 minutes, add 4 minutes to the clock and proceed to:

* 25 toes-to-bars
* 50 double-unders
* 9 squat cleans, 124/79 kg (275/175 lbs)

If completed before 16 minutes, add 4 minutes to the clock and proceed to:

* 25 toes-to-bars
* 50 double-unders
* 7 squat cleans, 142/93 kg (315/205 lbs)

Stop at 20 minutes
    `),
      Some(j`
Beginning on an 8-minute clock
If completed before 8 minutes, add 4 minutes to the clock and proceed to:

* 25 hanging knee-raises
* 50 single-unders
* 11 squat cleans, 61/43 kg (135/95 lbs)

If completed before 12 minutes, add 4 minutes to the clock and proceed to:

* 25 hanging knee-raises
* 50 single-unders
* 9 squat cleans, 70/52 kg (155/115 lbs)

If completed before 16 minutes, add 4 minutes to the clock and proceed to:

* 25 hanging knee-raises
* 50 single-unders
* 7 squat cleans, 83/61 kg (185/135 lbs)

Stop at 20 minutes
          `),
    )),
    ~parts=[
      make(~reps=#Num(25), ~exercise=#ToesToBar, ()),
      make(~reps=#Num(50), ~exercise=#DoubleUnder, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(61.0)), Some(#kg(38.0))), ~exercise=#CleanSquat, ()),
      make(~reps=#Num(25), ~exercise=#ToesToBar, ()),
      make(~reps=#Num(50), ~exercise=#DoubleUnder, ()),
      make(~reps=#Num(13), ~weight=(Some(#kg(83.0)), Some(#kg(52.0))), ~exercise=#CleanSquat, ()),
    ],
    ~scaledParts=Some([
      make(~reps=#Num(25), ~exercise=#HangingKneeRaise, ()),
      make(~reps=#Num(50), ~exercise=#SingleUnder, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(43.0)), Some(#kg(25.0))), ~exercise=#CleanSquat, ()),
      make(~reps=#Num(25), ~exercise=#HangingKneeRaise, ()),
      make(~reps=#Num(50), ~exercise=#SingleUnder, ()),
      make(~reps=#Num(13), ~weight=(Some(#kg(52.0)), Some(#kg(34.0))), ~exercise=#CleanSquat, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 19.3"),
    ~createdAt="2019-10-21T06:31:32.900Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(19)),
    ~timeCap=Some(10),
    ~externalLink=Some((
      "CrossFit Games Open 19.3",
      "https://games.crossfit.com/workouts/open/2019/3",
    )),
    ~parts=[
      make(
        ~reps=#MeterWithFeet(60),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#OverheadLunge,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#kgcm((22.5, 60.0))), Some(#kgcm((15.0, 45.0)))),
        ~exercise=#BoxStepUp,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(50), ~exercise=#HandstandPushUpStrict, ()),
      make(~reps=#MeterWithFeet(60), ~exercise=#HandstandWalk, ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#MeterWithFeet(60),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#LungeFrontRack,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#kgcm((22.5, 60.0))), Some(#kgcm((15.0, 45.0)))),
        ~exercise=#BoxStepUp,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(
        ~reps=#Num(50),
        ~weight=(Some(#cm(12.5)), Some(#cm(12.5))),
        ~exercise=#HandstandPushUpStrictElevated,
        (),
      ),
      make(~reps=#MeterWithFeet(60), ~exercise=#BearCrawl, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 19.4"),
    ~createdAt="2019-10-21T07:09:37.930Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(19)),
    ~rounds=Some(6),
    ~timeCap=Some(12),
    ~externalLink=Some((
      "CrossFit Games Open 19.4",
      "https://games.crossfit.com/workouts/open/2019/4",
    )),
    ~description=Some((
      Some("3 rounds of snatches and burpees. Then rest 3 minutes and do 3
               rounds of muscle ups and burpees"),
      Some("3 rounds of snatches and burpees. Then rest 3 minutes and do 3
               rounds of pull ups and burpees"),
    )),
    ~parts=[
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(43.0)), Some(#kg(29.0))),
        ~exercise=#Snatch,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(12), ~exercise=#BarFacingBurpee, ~equipment=Some(Barbell), ()),
      make(~reps=#Num(10), ~exercise=#BarMuscleUp, ()),
      make(~reps=#Num(12), ~exercise=#BarFacingBurpee, ~equipment=Some(Barbell), ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(29.0)), Some(#kg(20.0))),
        ~exercise=#Snatch,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(12), ~exercise=#BarFacingBurpee, ~equipment=Some(Barbell), ()),
      make(~reps=#Num(10), ~exercise=#PullUpChinOverBar, ()),
      make(~reps=#Num(12), ~exercise=#BarFacingBurpee, ~equipment=Some(Barbell), ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 19.5"),
    ~createdAt="2019-10-21T07:17:37.356Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(19)),
    ~timeCap=Some(20),
    ~repScheme=Some([33, 27, 21, 15, 9]),
    ~externalLink=Some((
      "CrossFit Games Open 19.5",
      "https://games.crossfit.com/workouts/open/2019/5",
    )),
    ~parts=[
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(43.0)), Some(#kg(29.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#RepScheme, ~exercise=#ChestToBar, ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#RepScheme,
        ~weight=(Some(#kg(29.0)), Some(#kg(20.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#RepScheme, ~exercise=#PullUpJumping, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 20.1"),
    ~createdAt="2019-10-19T05:34:55.721Z",
    ~wodType=#ForTime,
    ~rounds=Some(10),
    ~category=Some(#Open(20)),
    ~timeCap=Some(15),
    ~externalLink=Some((
      "CrossFit Games Open 20.1",
      "https://games.crossfit.com/workouts/open/2020/1",
    )),
    ~description=Some((None, Some("May step over bar on burpees"))),
    ~parts=[
      make(
        ~reps=#Num(8),
        ~weight=(Some(#kg(43.0)), Some(#kg(29.0))),
        ~exercise=#GroundToOverhead,
        (),
      ),
      make(~reps=#Num(10), ~exercise=#BarFacingBurpee, ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(8),
        ~weight=(Some(#kg(29.0)), Some(#kg(20.0))),
        ~exercise=#GroundToOverhead,
        (),
      ),
      make(~reps=#Num(10), ~exercise=#BarFacingBurpee, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 20.2"),
    ~createdAt="2019-10-19T05:45:48.630Z",
    ~wodType=#AMRAP,
    ~category=Some(#Open(20)),
    ~timeCap=Some(20),
    ~externalLink=Some((
      "CrossFit Games Open 20.2",
      "https://games.crossfit.com/workouts/open/2020/2",
    )),
    ~parts=[
      make(
        ~reps=#Num(4),
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(6), ~exercise=#ToesToBar, ()),
      make(~reps=#Num(24), ~exercise=#DoubleUnder, ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(4),
        ~weight=(Some(#kg(15.0)), Some(#kg(10.0))),
        ~exercise=#Thruster,
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(6), ~exercise=#HangingKneeRaise, ()),
      make(~reps=#Num(24), ~exercise=#SingleUnder, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 20.3"),
    ~createdAt="2019-10-25T14:18:31.008Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(20)),
    ~timeCap=Some(9),
    ~externalLink=Some((
      "CrossFit Games Open 20.3",
      "https://games.crossfit.com/workouts/open/2020/3",
    )),
    ~parts=[
      make(
        ~reps=#Num(21),
        ~weight=(Some(#kg(102.0)), Some(#kg(70.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(21), ~exercise=#HandstandPushUp, ()),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg(102.0)), Some(#kg(70.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#HandstandPushUp, ()),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(102.0)), Some(#kg(70.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(9), ~exercise=#HandstandPushUp, ()),
      make(
        ~reps=#Num(21),
        ~weight=(Some(#kg(143.0)), Some(#kg(93.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#HandstandWalk, ()),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg(143.0)), Some(#kg(93.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#HandstandWalk, ()),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(143.0)), Some(#kg(93.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#HandstandWalk, ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(21),
        ~weight=(Some(#kg(61.0)), Some(#kg(43.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(21), ~exercise=#HandReleasePushUp, ()),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg(61.0)), Some(#kg(43.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#HandReleasePushUp, ()),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(61.0)), Some(#kg(43.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(9), ~exercise=#HandReleasePushUp, ()),
      make(
        ~reps=#Num(21),
        ~weight=(Some(#kg(83.0)), Some(#kg(61.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#BearCrawl, ()),
      make(
        ~reps=#Num(15),
        ~weight=(Some(#kg(83.0)), Some(#kg(61.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#BearCrawl, ()),
      make(
        ~reps=#Num(9),
        ~weight=(Some(#kg(83.0)), Some(#kg(61.0))),
        ~exercise=#Deadlift,
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#MeterWithFeet(15), ~exercise=#BearCrawl, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 20.4"),
    ~createdAt="2019-11-01T06:53:20.948Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(20)),
    ~timeCap=Some(20),
    ~externalLink=Some((
      "CrossFit Games Open 20.4",
      "https://games.crossfit.com/workouts/open/2020/4",
    )),
    ~parts=[
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(43.0)), Some(#kg(29.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(61.0)), Some(#kg(38.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(10), ~weight=(Some(#kg(83.0)), Some(#kg(52.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~exercise=#SingleLegSquat, ()),
      make(
        ~reps=#Num(10),
        ~weight=(Some(#kg(102.0)), Some(#kg(65.0))),
        ~exercise=#CleanAndJerk,
        (),
      ),
      make(~reps=#Num(30), ~exercise=#SingleLegSquat, ()),
      make(~reps=#Num(5), ~weight=(Some(#kg(124.0)), Some(#kg(79.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~exercise=#SingleLegSquat, ()),
      make(~reps=#Num(5), ~weight=(Some(#kg(142.0)), Some(#kg(93.0))), ~exercise=#CleanAndJerk, ()),
    ],
    ~scaledParts=Some([
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(29.0)), Some(#kg(15.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(15), ~weight=(Some(#kg(43.0)), Some(#kg(25.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~weight=(Some(#cm(60.0)), Some(#cm(45.0))), ~exercise=#BoxJump, ()),
      make(~reps=#Num(10), ~weight=(Some(#kg(52.0)), Some(#kg(34.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~exercise=#MedicineBallStepUp, ()),
      make(~reps=#Num(10), ~weight=(Some(#kg(61.0)), Some(#kg(43.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~exercise=#MedicineBallStepUp, ()),
      make(~reps=#Num(5), ~weight=(Some(#kg(70.0)), Some(#kg(52.0))), ~exercise=#CleanAndJerk, ()),
      make(~reps=#Num(30), ~exercise=#MedicineBallStepUp, ()),
      make(~reps=#Num(5), ~weight=(Some(#kg(83.0)), Some(#kg(61.0))), ~exercise=#CleanAndJerk, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 20.5"),
    ~createdAt="2019-11-08T06:35:40.001Z",
    ~wodType=#ForTime,
    ~category=Some(#Open(20)),
    ~timeCap=Some(20),
    ~description=Some((
      Some("Partition work any way. Wall ball target 3.05/2.75 m
    (10/9 ft)"),
      None,
    )),
    ~externalLink=Some((
      "CrossFit Games Open 20.5",
      "https://games.crossfit.com/workouts/open/2020/5",
    )),
    ~parts=[
      make(~reps=#Num(40), ~exercise=#MuscleUp, ()),
      make(~reps=#Cal(80), ~exercise=#Row, ()),
      make(~reps=#Num(120), ~weight=(Some(#kg(9.0)), Some(#kg(6.0))), ~exercise=#WallBall, ()),
    ],
    ~scaledParts=Some([
      make(~reps=#Num(40), ~exercise=#PullUpChinOverBar, ()),
      make(~reps=#Cal(80), ~exercise=#Row, ()),
      make(~reps=#Num(120), ~weight=(Some(#kg(6.0)), Some(#kg(4.0))), ~exercise=#WallBall, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Luce"),
    ~createdAt="2020-07-18T12:19:00.000Z",
    ~wodType=#ForTime,
    ~rounds=Some(3),
    ~category=Some(#Wodapalooza(2020)),
    ~timeCap=Some(35),
    ~description=Some((Some("With a GORUCK (9/6 kg - 20/14 lbs)"), None)),
    ~externalLink=Some((
      "Wodapalooza",
      "https://wodapalooza.com/workout/2019-2020-wza-miami-luce/",
    )),
    ~parts=[
      make(~reps=#Meter(1000), ~exercise=#Run, ()),
      make(~reps=#Num2(10, 7), ~exercise=#MuscleUpRing, ()),
      make(~reps=#Num(100), ~exercise=#Squat, ()),
    ],
    (),
  ),
  Wod.make(
    ~name=Some("Pace Race"),
    ~createdAt="2020-07-18T12:35:00.000Z",
    ~wodType=#ForDistance,
    ~category=Some(#Wodapalooza(2020)),
    ~timeCap=Some(12),
    ~description=Some((
      Some(`Row until you are caught by the computer-generated pace-boat.

It will increase pace throughout the event`),
      None,
    )),
    ~externalLink=Some((
      "Wodapalooza",
      "https://wodapalooza.com/workout/2019-2020-wza-miami-pace-race/",
    )),
    ~parts=[make(~reps=#Max, ~exercise=#Row, ())],
    (),
  ),
  Wod.make(
    ~name=Some("Pump Sesh Triplet"),
    ~createdAt="2020-07-18T12:42:00.000Z",
    ~wodType=#ForTime,
    ~category=Some(#Wodapalooza(2020)),
    ~rounds=Some(3),
    ~timeCap=Some(8),
    ~externalLink=Some((
      "Wodapalooza",
      "https://wodapalooza.com/workout/2019-2020-wza-miami-pump-sesh-triplet/",
    )),
    ~parts=[
      make(~reps=#Num2(2, 1), ~exercise=#RopeClimbLegless, ~weight=(Some(#m(5.0)), None), ()),
      make(
        ~reps=#Num(15),
        ~exercise=#BenchPress,
        ~equipment=Some(Dumbbell),
        ~weight=(Some(#kg(31.0)), Some(#kg(22.5))),
        (),
      ),
      make(
        ~reps=#Num(9),
        ~exercise=#Thruster,
        ~equipment=Some(Dumbbell),
        ~weight=(Some(#kg(31.0)), Some(#kg(22.5))),
        (),
      ),
    ],
    ~scaledParts=Some([
      make(~reps=#Num2(2, 1), ~exercise=#RopeClimb, ~weight=(Some(#m(4.0)), None), ()),
      make(
        ~reps=#Num(15),
        ~exercise=#BenchPress,
        ~equipment=Some(Dumbbell),
        ~weight=(Some(#kg(18.0)), Some(#kg(11.0))),
        (),
      ),
      make(
        ~reps=#Num(9),
        ~exercise=#Thruster,
        ~equipment=Some(Dumbbell),
        ~weight=(Some(#kg(18.0)), Some(#kg(11.0))),
        (),
      ),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 21.1"),
    ~createdAt="2021-04-12T13:26:38.479Z",
    ~wodType=#ForTime,
    ~timeCap=Some(15),
    ~category=Some(#Open(21)),
    ~externalLink=Some((
      "CrossFit Games Open 21.1",
      "https://games.crossfit.com/workouts/open/2021",
    )),
    ~description=Some((None, Some("Scaled wall walks"))),
    ~parts=[
      make(~reps=#Num(1), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(10), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(3), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(30), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(6), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(60), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(9), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(90), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(15), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(150), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(21), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(210), ~exercise=#DoubleUnder, ~weight=(None, None), ~equipment=None, ()),
    ],
    ~scaledParts=Some([
      make(~reps=#Num(1), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(10), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(3), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(30), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(6), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(60), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(9), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(90), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(15), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(150), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(21), ~exercise=#WallWalk, ~weight=(None, None), ~equipment=None, ()),
      make(~reps=#Num(210), ~exercise=#SingleUnder, ~weight=(None, None), ~equipment=None, ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 21.2"),
    ~createdAt="2021-04-12T13:36:38.479Z",
    ~wodType=#ForTime,
    ~timeCap=Some(20),
    ~category=Some(#Open(21)),
    ~externalLink=Some((
      "CrossFit Games Open 21.2",
      "https://games.crossfit.com/workouts/open/2021/2",
    )),
    ~parts=[
      make(
        ~reps=#Num(10),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(60.)), Some(#cm(45.))), ()),
      make(
        ~reps=#Num(20),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(60.)), Some(#cm(45.))), ()),
      make(
        ~reps=#Num(30),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(60.)), Some(#cm(45.))), ()),
      make(
        ~reps=#Num(40),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(60.)), Some(#cm(45.))), ()),
      make(
        ~reps=#Num(50),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(22.5)), Some(#kg(15.0))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(60.)), Some(#cm(45.))), ()),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(10),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(15.)), Some(#kg(10.))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(45.)), None), ()),
      make(
        ~reps=#Num(20),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(15.)), Some(#kg(10.))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(45.)), None), ()),
      make(
        ~reps=#Num(30),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(15.)), Some(#kg(10.))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(45.)), None), ()),
      make(
        ~reps=#Num(40),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(15.)), Some(#kg(10.))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(45.)), None), ()),
      make(
        ~reps=#Num(50),
        ~exercise=#Snatch,
        ~weight=(Some(#kg(15.)), Some(#kg(10.))),
        ~equipment=Some(Dumbbell),
        (),
      ),
      make(~reps=#Num(15), ~exercise=#BurpeeBoxOver, ~weight=(Some(#cm(45.)), None), ()),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 21.3"),
    ~createdAt="2021-04-12T13:46:38.479Z",
    ~wodType=#ForTime,
    ~timeCap=Some(15),
    ~category=Some(#Open(21)),
    ~externalLink=Some((
      "CrossFit Games Open 21.3",
      "https://games.crossfit.com/workouts/open/2021/3",
    )),
    ~description=Some(
      Some("Workout 21.4 begins immediately upon completing or reaching the time cap for 21.3."),
      None,
    ),
    ~parts=[
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#ToesToBar, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Min(1), ~exercise=#Rest, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#ChestToBar, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Min(1), ~exercise=#Rest, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#BarMuscleUp, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(43.)), Some(#kg(29.))),
        ~equipment=Some(Barbell),
        (),
      ),
    ],
    ~scaledParts=Some([
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#HangingKneeRaise, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Min(1), ~exercise=#Rest, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#PullUpChinOverBar, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Min(1), ~exercise=#Rest, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#FrontSquat,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
      make(~reps=#Num(30), ~exercise=#ChestToBar, ()),
      make(
        ~reps=#Num(15),
        ~exercise=#Thruster,
        ~weight=(Some(#kg(29.)), Some(#kg(20.))),
        ~equipment=Some(Barbell),
        (),
      ),
    ]),
    (),
  ),
  Wod.make(
    ~name=Some("Open 21.4"),
    ~createdAt="2021-04-12T13:56:38.479Z",
    ~wodType=#ForTime,
    ~timeCap=Some(7),
    ~category=Some(#Open(21)),
    ~externalLink=Some((
      "CrossFit Games Open 21.4",
      "https://games.crossfit.com/workouts/open/2021/4",
    )),
    ~description=Some(Some("Complete the following complex for max load"), None),
    ~parts=[
      make(~reps=#Num(1), ~exercise=#Deadlift, ()),
      make(~reps=#Num(1), ~exercise=#Clean, ()),
      make(~reps=#Num(1), ~exercise=#CleanHang, ()),
      make(~reps=#Num(1), ~exercise=#Jerk, ()),
    ],
    (),
  ),
]
