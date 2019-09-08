type t = {
  id: CUID.Generate.t,
  weight: (option(Weight.t), option(Weight.t)),
  reps: ExerciseUnit.t,
  exercise: Exercise.t,
  equipment: option(Equipment.t),
};

let make = (~exercise, ~reps, ~weight=(None, None), ~equipment=None, ()) => {
  id: CUID.Generate.make(),
  exercise,
  reps,
  weight,
  equipment,
};

let rest = min => {
  make(~reps=`Min(min), ~exercise=`Rest, ());
};
