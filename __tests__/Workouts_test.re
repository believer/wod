open Jest;
open Expect;
open Workouts;

describe("#workoutType", () => {
  test("handles alternating EMOM", () =>
    expect(Filter.workoutType(Some(EMOM), `AltEMOM(0))) |> toBe(true)
  );

  test("handles EMOM", () =>
    expect(Filter.workoutType(Some(EMOM), `EMOM(0))) |> toBe(true)
  );

  testAll("handles non-EMOM", [`AMRAP, `ForTime], value =>
    expect(Filter.workoutType(Some(EMOM), value)) |> toBe(false)
  );

  test("handles AMRAP", () =>
    expect(Filter.workoutType(Some(AMRAP), `AMRAP)) |> toBe(true)
  );

  testAll("handles non-AMRAP", [`AltEMOM(0), `EMOM(0), `ForTime], value =>
    expect(Filter.workoutType(Some(AMRAP), value)) |> toBe(false)
  );

  test("handles For Time", () =>
    expect(Filter.workoutType(Some(ForTime), `ForTime)) |> toBe(true)
  );

  testAll("handles non-AMRAP", [`AltEMOM(0), `EMOM(0), `AMRAP], value =>
    expect(Filter.workoutType(Some(ForTime), value)) |> toBe(false)
  );
});

describe("#category", () => {
  test("handles WZA", () =>
    expect(Filter.category(Some(WZA), Some(`Wodapalooza(0))))
    |> toBe(true)
  );

  testAll("handles non-WZA", [`Open(0), `Girl, `Hero], value =>
    expect(Filter.category(Some(WZA), Some(value))) |> toBe(false)
  );

  test("handles Open", () =>
    expect(Filter.category(Some(Open), Some(`Open(0)))) |> toBe(true)
  );

  testAll("handles non-Open", [`Wodapalooza(0), `Girl, `Hero], value =>
    expect(Filter.category(Some(Open), Some(value))) |> toBe(false)
  );

  test("handles Girl", () =>
    expect(Filter.category(Some(Girl), Some(`Girl))) |> toBe(true)
  );

  testAll("handles non-Girl", [`Wodapalooza(0), `Open(0), `Hero], value =>
    expect(Filter.category(Some(Girl), Some(value))) |> toBe(false)
  );

  test("handles Hero", () =>
    expect(Filter.category(Some(Hero), Some(`Hero))) |> toBe(true)
  );

  testAll("handles non-Hero", [`Wodapalooza(0), `Open(0), `Girl], value =>
    expect(Filter.category(Some(Hero), Some(value))) |> toBe(false)
  );
});
