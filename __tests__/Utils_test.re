open Jest;
open Expect;

describe("#capitalizeFirst", () =>
  test("capitalizes first letter of any string", () =>
    expect(Utils.capitalizeFirst("bla bla bla")) |> toEqual("Bla bla bla")
  )
);
