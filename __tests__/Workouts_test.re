open Jest;
open Expect;

describe("#filterWorkoutType", () => {
  test("handles alternating EMOM", () =>
    expect(Workouts.filterWorkoutType(Some(EMOM), `AltEMOM(0)))
    |> toBe(true)
  );

  test("handles EMOM", () =>
    expect(Workouts.filterWorkoutType(Some(EMOM), `EMOM(0))) |> toBe(true)
  );

  testAll("handles non-EMOM", [`AMRAP, `ForTime], value =>
    expect(Workouts.filterWorkoutType(Some(EMOM), value)) |> toBe(false)
  );

  test("handles AMRAP", () =>
    expect(Workouts.filterWorkoutType(Some(AMRAP), `AMRAP)) |> toBe(true)
  );

  testAll("handles non-AMRAP", [`AltEMOM(0), `EMOM(0), `ForTime], value =>
    expect(Workouts.filterWorkoutType(Some(AMRAP), value)) |> toBe(false)
  );

  test("handles For Time", () =>
    expect(Workouts.filterWorkoutType(Some(ForTime), `ForTime))
    |> toBe(true)
  );

  testAll("handles non-AMRAP", [`AltEMOM(0), `EMOM(0), `AMRAP], value =>
    expect(Workouts.filterWorkoutType(Some(ForTime), value)) |> toBe(false)
  );
});

describe("#filterWorkoutCategory", () => {
  test("handles WZA", () =>
    expect(
      Workouts.filterWorkoutCategory(Some(WZA), Some(`Wodapalooza(0))),
    )
    |> toBe(true)
  );

  testAll("handles non-WZA", [`Open(0), `Girl, `Hero], value =>
    expect(Workouts.filterWorkoutCategory(Some(WZA), Some(value)))
    |> toBe(false)
  );

  test("handles Open", () =>
    expect(Workouts.filterWorkoutCategory(Some(Open), Some(`Open(0))))
    |> toBe(true)
  );

  testAll("handles non-Open", [`Wodapalooza(0), `Girl, `Hero], value =>
    expect(Workouts.filterWorkoutCategory(Some(Open), Some(value)))
    |> toBe(false)
  );

  test("handles Girl", () =>
    expect(Workouts.filterWorkoutCategory(Some(Girl), Some(`Girl)))
    |> toBe(true)
  );

  testAll("handles non-Girl", [`Wodapalooza(0), `Open(0), `Hero], value =>
    expect(Workouts.filterWorkoutCategory(Some(Girl), Some(value)))
    |> toBe(false)
  );

  test("handles Hero", () =>
    expect(Workouts.filterWorkoutCategory(Some(Hero), Some(`Hero)))
    |> toBe(true)
  );

  testAll("handles non-Hero", [`Wodapalooza(0), `Open(0), `Girl], value =>
    expect(Workouts.filterWorkoutCategory(Some(Hero), Some(value)))
    |> toBe(false)
  );
});
