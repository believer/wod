let soi = string_of_int;
let str = React.string;

module Equipment = {
  [@react.component]
  let make = (~equipment) => {
    switch (equipment) {
    | Some(eq) =>
      switch (eq) {
      | `BulgarianBag
      | `Kettlebell
      | `Dumbbell => " " ++ Wod.Equipment.toString(eq) |> str
      | _ => React.null
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
      | `Cal(c) => c->soi ++ " kcal "
      | `Num(st) => st->soi
      | `Meter(m) => m->soi ++ "m "
      | `OneSide(a, b) => a->soi ++ "/" ++ b->soi
      }
    )
    |> React.string;
  };
};

let weightUnit =
  fun
  | `Bodyweight => ""
  | `Cm(_) => "cm"
  | `Kg(_)
  | `Kg2(_) => "kg";

let splitWeight = (~m, ~f, ~weight as w) =>
  switch (w) {
  | `Kg2(_) =>
    str("(2*" ++ m->soi ++ "/" ++ f->soi ++ " " ++ weightUnit(w) ++ ")")
  | _ => str("(" ++ m->soi ++ "/" ++ f->soi ++ " " ++ weightUnit(w) ++ ")")
  };

let singleWeight = (~m, ~weight as w) =>
  switch (w) {
  | `Kg2(_) => str("(2*" ++ m->soi ++ " " ++ weightUnit(w) ++ ")")
  | _ => str("(" ++ m->soi ++ " " ++ weightUnit(w) ++ ")")
  };

module Weight = {
  [@react.component]
  let make = (~weight) => {
    <span className="text-gray-500">
      {switch (weight) {
       | (Some(male), Some(female)) =>
         switch (male, female) {
         | (`Kg2(m), `Kg2(f)) => splitWeight(~m, ~f, ~weight=male)
         | (`Cm(m), `Cm(f)) => splitWeight(~m, ~f, ~weight=male)
         | (`Kg(m), `Kg(f)) => splitWeight(~m, ~f, ~weight=male)
         | (`Bodyweight, `Bodyweight) => React.null
         | (_, _) => str("Non-uniform weights")
         }
       | (None, Some(weight))
       | (Some(weight), None) =>
         switch (weight) {
         | `Kg2(m) => singleWeight(~m, ~weight)
         | `Kg(m) => singleWeight(~m, ~weight)
         | `Cm(m) => singleWeight(~m, ~weight)
         | `Bodyweight => React.null
         }
       | (None, None) => React.null
       }}
    </span>;
  };
};
