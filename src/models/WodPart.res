type t = {
  id: CUID.t,
  weight: (option<Weight.t>, option<Weight.t>),
  reps: ExerciseUnit.t,
  exercise: Exercise.t,
  equipment: option<Equipment.t>,
}

let make = (~exercise, ~reps, ~weight=(None, None), ~equipment=None, ()) => {
  id: CUID.make(),
  exercise: exercise,
  reps: reps,
  weight: weight,
  equipment: equipment,
}

let rest = min => make(~reps=#Min(min), ~exercise=#Rest, ())
