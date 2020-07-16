type rec t = {
  category: option<Category.t>,
  buyInOut: option<(option<WodPart.t>, option<WodPart.t>)>,
  createdAt: string,
  description: option<(option<string>, option<string>)>,
  id: CUID.t,
  externalLink: option<(string, string)>,
  name: option<string>,
  wodType: WodType.t,
  timeCap: option<int>,
  rounds: option<int>,
  repScheme: option<RepScheme.t>,
  parts: array<WodPart.t>,
  scaledParts: option<array<WodPart.t>>,
}

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
  id: CUID.make(),
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
}