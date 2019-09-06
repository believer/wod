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

let make =
    (
      ~createdAt,
      ~parts,
      ~wodType,
      ~buyInOut=None,
      ~category=None,
      ~description=None,
      ~name=None,
      ~externalLink=None,
      ~timeCap=None,
      ~rounds=None,
      ~repScheme=None,
      ~scaledParts=None,
      (),
    ) => {
  id:
    switch (name) {
    | Some(name) => Js.String.toLowerCase(name)
    | None => Utils.UUID.make()->Utils.UUID.toString
    },
  buyInOut,
  category,
  createdAt,
  description,
  name,
  externalLink,
  wodType,
  timeCap,
  rounds,
  repScheme,
  scaledParts,
  parts,
};
