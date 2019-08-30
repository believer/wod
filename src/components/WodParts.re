let soi = string_of_int;
let sof = Js.Float.toString;
let str = React.string;

module Equipment = {
  [@react.component]
  let make = (~equipment) => {
    switch (equipment) {
    | Some(eq) =>
      switch (eq) {
      | `BulgarianBag
      | `Dumbbell => " " ++ Equipment.toString(eq) |> str
      | `WallBall
      | `Barbell
      | `JumpRope
      | `Kettlebell => React.null
      }
    | None => React.null
    };
  };
};

module Unit = {
  [@react.component]
  let make = (~reps) => {
    (
      switch (reps) {
      | `Increasing(i) => "+" ++ i->soi
      | `Min(min) => min->soi ++ " min "
      | `RepScheme => ""
      | `Cal(c) => c->soi ++ " cal "
      | `Cal2(m, f) => m->soi ++ "/" ++ f->soi ++ " cal "
      | `Num(st) => st->soi
      | `Meter(m) => m->soi ++ "m "
      | `OneSide(a, b) => a->soi ++ "/" ++ b->soi
      | `Span(a, b) =>
        switch (a, b) {
        | (`Num(ast), `Num(bst)) => ast->soi ++ "-" ++ bst->soi
        | (`Cal(ast), `Cal(bst)) => ast->soi ++ "-" ++ bst->soi ++ " cal "
        | (`OneSide(aa, ab), `OneSide(ba, bb)) =>
          aa->soi ++ "/" ++ ab->soi ++ "-" ++ ba->soi ++ "/" ++ bb->soi
        | _ => ""
        }
      }
    )
    |> React.string;
  };
};

let weightUnit =
  fun
  | `lbs => "lbs"
  | `cm(_) => "cm"
  | `inch => "in"
  | `kg(_)
  | `kg2(_) => "kg"
  | `bodyweight
  | `kg2cm(_, _) => "";

let round5 = x => Js.Math.ceil_float(x /. 5.0) *. 5.0;

module Pounds = {
  let approx = 2.205;

  let make = kg =>
    switch (kg) {
    | 13.0 => 33.0
    | 25.0 => 55.0
    | _ => (kg *. approx)->round5
    };
};

module Inches = {
  let approx = 2.54;

  let make = cm =>
    switch (cm) {
    | 60.0 => 24.0
    | 45.0 => 20.0
    | _ => (cm /. approx)->round5
    };
};

let splitWeight = (~m, ~f, ~weight as w, ~system) =>
  switch (system) {
  | Settings.Metric =>
    switch (w) {
    | `kg2(_) =>
      str("(2*" ++ m->sof ++ "/" ++ f->sof ++ " " ++ weightUnit(w) ++ ")")
    | _ => str("(" ++ m->sof ++ "/" ++ f->sof ++ " " ++ weightUnit(w) ++ ")")
    }
  | Settings.Imperial =>
    switch (w) {
    | `kg2(_) =>
      str(
        "(2*"
        ++ m->Pounds.make->sof
        ++ "/"
        ++ f->Pounds.make->sof
        ++ " "
        ++ weightUnit(`lbs)
        ++ ")",
      )
    | `kg(_) =>
      str(
        "("
        ++ m->Pounds.make->sof
        ++ "/"
        ++ f->Pounds.make->sof
        ++ " "
        ++ weightUnit(`lbs)
        ++ ")",
      )
    | `cm(_) =>
      str(
        "("
        ++ m->Inches.make->sof
        ++ "/"
        ++ f->Inches.make->sof
        ++ " "
        ++ weightUnit(`inch)
        ++ ")",
      )
    | _ => str("(" ++ m->sof ++ "/" ++ f->sof ++ " " ++ weightUnit(w) ++ ")")
    }
  };

let weightAndHeight =
    (~maleWeight, ~maleHeight, ~femaleWeight, ~femaleHeight, ~system) => {
  switch (system) {
  | Settings.Metric =>
    str(
      "(2*"
      ++ maleWeight->sof
      ++ "/"
      ++ femaleWeight->sof
      ++ " "
      ++ weightUnit(`kg(0))
      ++ " - "
      ++ maleHeight->sof
      ++ "/"
      ++ femaleHeight->sof
      ++ " "
      ++ weightUnit(`cm(0))
      ++ ")",
    )
  | Settings.Imperial =>
    str(
      "(2*"
      ++ maleWeight->Pounds.make->sof
      ++ "/"
      ++ femaleWeight->Pounds.make->sof
      ++ " "
      ++ weightUnit(`lbs)
      ++ " - "
      ++ maleHeight->Inches.make->sof
      ++ "/"
      ++ femaleHeight->Inches.make->sof
      ++ " "
      ++ weightUnit(`inch)
      ++ ")",
    )
  };
};

let singleWeight = (~m, ~weight as w) =>
  switch (w) {
  | `kg2(_) => str("(2*" ++ m->sof ++ " " ++ weightUnit(w) ++ ")")
  | _ => str("(" ++ m->sof ++ " " ++ weightUnit(w) ++ ")")
  };

module Weight = {
  [@react.component]
  let make = (~weight) => {
    let {system}: Settings.t = Settings.use();

    <span className="text-gray-500">
      {switch (weight) {
       | (Some(male), Some(female)) =>
         switch (male, female) {
         | (`kg2cm(m, mcm), `kg2cm(f, fcm)) =>
           weightAndHeight(
             ~maleWeight=m,
             ~maleHeight=mcm,
             ~femaleWeight=f,
             ~femaleHeight=fcm,
             ~system,
           )
         | (`kg(m), `kg(f))
         | (`kg2(m), `kg2(f))
         | (`cm(m), `cm(f)) => splitWeight(~m, ~f, ~weight=male, ~system)
         | (`bodyweight, `bodyweight) => React.null
         | (_, _) => str("Non-uniform weights")
         }
       | (None, Some(weight))
       | (Some(weight), None) =>
         switch (weight) {
         | `kg(m)
         | `kg2(m)
         | `cm(m) => singleWeight(~m, ~weight)
         | `kg2cm(_, _)
         | `bodyweight => React.null
         }
       | (None, None) => React.null
       }}
    </span>;
  };
};
