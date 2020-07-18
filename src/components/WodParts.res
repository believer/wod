let soi = string_of_int
let sof = Js.Float.toString
let str = React.string

let round5 = x => Js.Math.ceil_float(x /. 5.0) *. 5.0

module Pounds = {
  let approx = 2.205

  let make = kg =>
    switch kg {
    | 6.0 => 14.0
    | 10.0 => 20.0
    | 13.0 => 33.0
    | 25.0 => 55.0
    | 30.0 => 65.0
    | 93.0 => 205.0
    | 143.0 => 315.0
    | _ => (kg *. approx)->round5
    }
}

module Inches = {
  let approx = 2.54

  let make = cm =>
    switch cm {
    | 60.0 => 24.0
    | 45.0 => 20.0
    | _ => (cm /. approx)->round5
    }
}

module Feet = {
  let approx = 3.28084

  let make = m =>
    switch m {
    | _ => (m *. approx)->round5
    }
}

module Equipment = {
  @react.component
  let make = (~equipment) => {
    switch equipment {
    | Some(eq) =>
      switch eq {
      | Equipment.BulgarianBag
      | Unbroken
      | Kettlebell
      | Dumbbell => " " ++ Equipment.toString(eq) |> str
      | WallBall
      | Barbell
      | JumpRope => React.null
      }
    | None => React.null
    }
  }
}

module Unit = {
  @react.component
  let make = (~reps) => {
    let {system}: Settings.t = Settings.use()

    switch reps {
    | #Increasing(i) => "+" ++ i->soi
    | #Min(min) => min->soi ++ " min "
    | #RepScheme => ""
    | #Cal(c) => c->soi ++ " cal "
    | #Cal2(m, f) => `${m->soi}/${f->soi} cal `
    | #Num(st) => st->soi
    | #Num2(m, f) => `${m->soi}/${f->soi} `
    | #Max => "Max "
    | #Meter(m) => m->soi ++ "m "
    | #MeterWithFeet(m) =>
      switch system {
      | Metric => m->soi ++ "m "
      | Imperial => m->float_of_int->Feet.make->sof ++ " feet "
      }
    | #OneSide(a, b) => a->soi ++ "/" ++ b->soi
    | #Span(a, b) =>
      switch (a, b) {
      | (#Num(ast), #Num(bst)) => ast->soi ++ "-" ++ bst->soi
      | (#Cal(ast), #Cal(bst)) => ast->soi ++ "-" ++ bst->soi ++ " cal "
      | (#OneSide(aa, ab), #OneSide(ba, bb)) =>
        aa->soi ++ "/" ++ ab->soi ++ "-" ++ ba->soi ++ "/" ++ bb->soi
      | _ => ""
      }
    }
    |> React.string
  }
}

let weightUnit = weight =>
  switch weight {
  | #lbs => "lbs"
  | #cm(_) => "cm"
  | #m(_) => "m"
  | #inch => "in"
  | #feet => "ft"
  | #kg(_)
  | #kg2(_) => "kg"
  | #bodyweight
  | #kg2cm(_, _)
  | #kgcm(_, _) => ""
  }

module Split = {
  let toString = (~m, ~f, ~w, ~prefix="(", ()) => {
    str(prefix ++ m->sof ++ "/" ++ f->sof ++ " " ++ weightUnit(w) ++ ")")
  }

  let make = (~m, ~f, ~weight as w, ~system) =>
    switch (system) {
    | Settings.Metric =>
      switch (w) {
      | #kg2(_) => toString(~m, ~f, ~w, ~prefix="(2*", ())
      | _ => toString(~m, ~f, ~w, ())
      }
    | Settings.Imperial =>
      switch (w) {
      | #kg2(_) =>
        toString(
          ~m=Pounds.make(m),
          ~f=Pounds.make(f),
          ~w=#lbs,
          ~prefix="(2*",
          (),
        )
      | #kg(_) =>
        toString(~m=Pounds.make(m), ~f=Pounds.make(f), ~w=#lbs, ())
      | #cm(_) =>
        toString(~m=Inches.make(m), ~f=Inches.make(f), ~w=#inch, ())
      | #m(_) => toString(~m=Feet.make(m), ~f=Feet.make(f), ~w=#feet,
      ())
      | _ => toString(~m, ~f, ~w, ())
      }
    }
}

let weightAndHeight =
    (~maleWeight, ~maleHeight, ~femaleWeight, ~femaleHeight, ~system, ~weight) => {
  switch (system, weight) {
  | (Settings.Metric, #kgcm) =>
    str(
      "("
      ++ maleWeight->sof
      ++ "/"
      ++ femaleWeight->sof
      ++ " "
      ++ weightUnit(#kg(0))
      ++ " - "
      ++ maleHeight->sof
      ++ "/"
      ++ femaleHeight->sof
      ++ " "
      ++ weightUnit(#cm(0))
      ++ ")",
    )
  | (Settings.Imperial, #kgcm) =>
    str(
      "("
      ++ maleWeight->Pounds.make->sof
      ++ "/"
      ++ femaleWeight->Pounds.make->sof
      ++ " "
      ++ weightUnit(#lbs)
      ++ " - "
      ++ maleHeight->Inches.make->sof
      ++ "/"
      ++ femaleHeight->Inches.make->sof
      ++ " "
      ++ weightUnit(#inch)
      ++ ")",
    )

  | (Settings.Metric, #kg2cm) =>
    str(
      "(2*"
      ++ maleWeight->sof
      ++ "/"
      ++ femaleWeight->sof
      ++ " "
      ++ weightUnit(#kg(0))
      ++ " - "
      ++ maleHeight->sof
      ++ "/"
      ++ femaleHeight->sof
      ++ " "
      ++ weightUnit(#cm(0))
      ++ ")",
    )
  | (Settings.Imperial, #kg2cm) =>
    str(
      "(2*"
      ++ maleWeight->Pounds.make->sof
      ++ "/"
      ++ femaleWeight->Pounds.make->sof
      ++ " "
      ++ weightUnit(#lbs)
      ++ " - "
      ++ maleHeight->Inches.make->sof
      ++ "/"
      ++ femaleHeight->Inches.make->sof
      ++ " "
      ++ weightUnit(#inch)
      ++ ")",
    )
  }
}

let singleWeight = (~m, ~weight as w, ~system) =>
  switch system {
  | Settings.Metric => 
    switch w {
    | #kg2(_) => str("(2*" ++ m->sof ++ " " ++ weightUnit(w) ++ ")")
    | _ => str("(" ++ m->sof ++ " " ++ weightUnit(w) ++ ")")
    }
  | Imperial =>
    switch w {
    | #m(_) => str(`(${m->Feet.make->sof} ${weightUnit(#feet)})`)
    | _ => str("(" ++ m->sof ++ " " ++ weightUnit(w) ++ ")")
    }
  }

module Weight = {
  @react.component
  let make = (~weight) => {
    let {system}: Settings.t = Settings.use()

    <span className="text-gray-500">
      {switch weight {
       | (Some(male), Some(female)) =>
         switch (male, female) {
         | (#kgcm(m, mcm), #kgcm(f, fcm)) =>
           weightAndHeight(
             ~maleWeight=m,
             ~maleHeight=mcm,
             ~femaleWeight=f,
             ~femaleHeight=fcm,
             ~system,
             ~weight=#kgcm,
           )
         | (#kg2cm(m, mcm), #kg2cm(f, fcm)) =>
           weightAndHeight(
             ~maleWeight=m,
             ~maleHeight=mcm,
             ~femaleWeight=f,
             ~femaleHeight=fcm,
             ~system,
             ~weight=#kgcm,
           )
         | (#kg(m), #kg(f))
         | (#kg2(m), #kg2(f))
         | (#m(m), #m(f))
         | (#cm(m), #cm(f)) => Split.make(~m, ~f, ~weight=male, ~system)
         | (#bodyweight, #bodyweight) => React.null
         | (_, _) => str("Non-uniform weights")
         }
       | (None, Some(weight))
       | (Some(weight), None) =>
         switch weight {
         | #kg(m)
         | #kg2(m)
         | #m(m)
         | #cm(m) => singleWeight(~m, ~weight, ~system)
         | #kgcm(_, _)
         | #kg2cm(_, _)
         | #bodyweight => React.null
         }
       | (None, None) => React.null
       }}
    </span>
  }
}
