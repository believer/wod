open Jest;
open Expect;

describe("Split", () => {
  testAll(
    "handles metric",
    [
      (15.0, 10.0, `kg(15.0), "(15/10 kg)"),
      (15.0, 10.0, `kg2(15.0), "(2*15/10 kg)"),
      (60.0, 45.0, `cm(60.0), "(60/45 cm)"),
    ],
    ((m, f, weight, result)) =>
    WodParts.Split.make(~m, ~f, ~weight, ~system=Settings.Metric)
    |> expect
    |> toEqual(React.string(result))
  );

  testAll(
    "handles imperial",
    [
      (15.0, 10.0, `kg(15.0), "(35/25 lbs)"),
      (15.0, 10.0, `kg2(15.0), "(2*35/25 lbs)"),
      (60.0, 45.0, `cm(60.0), "(24/20 in)"),
    ],
    ((m, f, weight, result)) =>
    WodParts.Split.make(~m, ~f, ~weight, ~system=Settings.Imperial)
    |> expect
    |> toEqual(React.string(result))
  );
});
