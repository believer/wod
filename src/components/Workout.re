type t =
  | RX
  | Scaled;

module NewTag = {
  [@react.component]
  let make = (~lastVisit, ~createdAt) => {
    switch (lastVisit) {
    | Some(last) =>
      Js.Date.fromString(createdAt)
      |> Js.Date.getTime > (Js.Date.fromString(last) |> Js.Date.getTime)
        ? <div
            className="mb-4 uppercase rounded bg-green-200 text-xs text-green-700 inline-block px-2 py-1">
            {React.string("New")}
          </div>
        : React.null
    | None => React.null
    };
  };
};

module Header = {
  [@react.component]
  let make = (~wod: Wod.t) => {
    <header className="flex items-center justify-between">
      <div className="font-bold">
        {switch (wod.name) {
         | Some(name) => React.string(name)
         | None => React.string(WodType.toString(wod.wodType))
         }}
        {switch (wod.timeCap, wod.wodType, wod.name) {
         | (Some(t), `AMRAP, None) =>
           t->string_of_int
           ++ " min"
           |> Utils.padStartWithSpace
           |> React.string
         | (Some(_), _, _)
         | (None, _, _) => React.null
         }}
      </div>
      {switch (wod.category) {
       | Some(c) =>
         switch (c) {
         | `Hero => <Pill background=`Green> {React.string("Hero")} </Pill>
         | `Girl =>
           <Pill background=`Pink> {React.string("The Girls")} </Pill>
         | `Wodapalooza(year) =>
           <Pill>
             {React.string("Wodapalooza " ++ year->string_of_int)}
           </Pill>
         | `Open(year, num, style) =>
           switch (style) {
           | `Scaled =>
             <Pill>
               {React.string(
                  "Open "
                  ++ year->string_of_int
                  ++ "."
                  ++ num->string_of_int
                  ++ " (Scaled)",
                )}
             </Pill>
           | `RX =>
             <Pill>
               {React.string(
                  "Open " ++ year->string_of_int ++ "." ++ num->string_of_int,
                )}
             </Pill>
           }
         | `Mayhem => React.null
         }
       | None => React.null
       }}
    </header>;
  };
};

module AltEMOM = {
  [@react.component]
  let make = (~wod: Wod.t) => {
    switch (wod.wodType) {
    | `AltEMOM(min) =>
      <div className="text-sm text-gray-500">
        {(min / wod.parts->Belt.List.length)->string_of_int
         ++ " of each"
         |> React.string}
      </div>
    | _ => React.null
    };
  };
};

module Rounds = {
  [@react.component]
  let make = (~rounds) => {
    switch (rounds) {
    | Some(r) =>
      <div className="text-sm text-gray-500">
        {r->string_of_int ++ " rounds for time of:" |> React.string}
      </div>
    | None => React.null
    };
  };
};

module RepScheme = {
  [@react.component]
  let make = (~repScheme) => {
    switch (repScheme) {
    | Some(scheme) =>
      <div className="mt-4 text-gray-700">
        {scheme->Belt.List.reduceWithIndex("", (acc, curr, i) =>
           switch (i) {
           | 0 => curr->string_of_int
           | _ => acc ++ "-" ++ curr->string_of_int
           }
         )
         ++ " reps for time of:"
         |> React.string}
      </div>
    | None => React.null
    };
  };
};

module NamedAMRAP = {
  [@react.component]
  let make = (~wod) => {
    let {timeCap, wodType, name}: Wod.t = wod;

    switch (timeCap, wodType, name) {
    | (Some(t), `AMRAP, Some(_)) =>
      <div className="mt-4 text-gray-700 text-sm">
        <span className="font-semibold"> {React.string("AMRAP:")} </span>
        {t->string_of_int ++ " min" |> Utils.padStartWithSpace |> React.string}
      </div>
    | (Some(_), _, _)
    | (None, _, _) => React.null
    };
  };
};

module BuyIn = {
  [@react.component]
  let make = (~buyIn: option(Wod.WodPart.t)) => {
    switch (buyIn) {
    | Some(buyIn) =>
      <div className="mt-4">
        <strong> {React.string("Buy-in: ")} </strong>
        <WodParts.Unit reps={buyIn.reps} />
        <WodParts.Equipment equipment={buyIn.equipment} />
        {Exercise.toString(buyIn.exercise) |> React.string}
        <WodParts.Weight weight={buyIn.weight} />
      </div>
    | None => React.null
    };
  };
};

module BuyOut = {
  [@react.component]
  let make = (~buyOut: option(Wod.WodPart.t)) => {
    switch (buyOut) {
    | Some(buyOut) =>
      <div className="mt-4">
        <strong> {React.string("Buy-out: ")} </strong>
        <WodParts.Unit reps={buyOut.reps} />
        <WodParts.Equipment equipment={buyOut.equipment} />
        {Exercise.toString(buyOut.exercise) |> React.string}
        <WodParts.Weight weight={buyOut.weight} />
      </div>
    | None => React.null
    };
  };
};

module WodItem = {
  let toElements = (~parts: list(Wod.WodPart.t), ~wod: Wod.t) => {
    parts
    ->Belt.List.mapWithIndex((i, part) =>
        <li key={i->string_of_int}>
          <WodParts.Unit reps={part.reps} />
          <WodParts.Equipment equipment={part.equipment} />
          {(
             switch (wod.repScheme) {
             | Some(_) =>
               part.exercise->Exercise.toString->Utils.capitalizeFirst
             | None => Exercise.toString(part.exercise)
             }
           )
           |> Utils.padStartWithSpace
           |> Utils.padEndWithSpace
           |> React.string}
          <WodParts.Weight weight={part.weight} />
        </li>
      )
    ->Belt.List.toArray
    ->React.array;
  };
};

module TimeCap = {
  [@react.component]
  let make = (~wod: Wod.t) => {
    switch (wod.timeCap, wod.wodType) {
    | (Some(t), `ForTime) =>
      <div className="mt-4 text-sm text-gray-700">
        <span className="font-semibold">
          {"Time cap:"->Utils.padEndWithSpace->React.string}
        </span>
        {t->string_of_int ++ " min" |> React.string}
      </div>
    | (Some(_), _)
    | (None, _) => React.null
    };
  };
};

[@react.component]
let make = (~lastVisit, ~wod: Wod.t) => {
  let (wodVersion, setWodVersion) = React.useState(() => RX);

  let (buyIn, buyOut) =
    switch (wod.buyInOut) {
    | Some((Some(buyIn), Some(buyOut))) => (Some(buyIn), Some(buyOut))
    | Some((Some(buyIn), None)) => (Some(buyIn), None)
    | Some((None, Some(buyOut))) => (None, Some(buyOut))
    | Some((None, _))
    | None => (None, None)
    };

  <div className="bg-white rounded shadow-lg flex flex-col justify-between">
    <div className="p-6">
      <NewTag createdAt={wod.createdAt} lastVisit />
      <Header wod />
      <AltEMOM wod />
      <Rounds rounds={wod.rounds} />
      <RepScheme repScheme={wod.repScheme} />
      <NamedAMRAP wod />
      <BuyIn buyIn />
      <ul className="text-gray-700 mt-4">
        {switch (wodVersion) {
         | RX => WodItem.toElements(~parts=wod.parts, ~wod)
         | Scaled =>
           WodItem.toElements(
             ~parts=wod.scaledParts->Belt.Option.getWithDefault([]),
             ~wod,
           )
         }}
      </ul>
      <BuyOut buyOut />
      <TimeCap wod />
      {switch (wod.description) {
       | Some(text) => <Markdown text />
       | None => React.null
       }}
      {switch (wod.externalLink) {
       | Some((name, href)) =>
         <Router.ExternalLink href>
           {React.string(name)}
         </Router.ExternalLink>
       | None => React.null
       }}
    </div>
    {switch (wod.scaledParts) {
     | Some(_) =>
       <button
         className="bg-gray-200 rounded-b py-3 text-sm text-gray-600
                   font-semibold hover:bg-gray-300"
         onClick={_ => setWodVersion(_ => wodVersion === RX ? Scaled : RX)}
         type_="button">
         {switch (wodVersion) {
          | RX => React.string("Switch to scaled")
          | Scaled => React.string("Switch to RX")
          }}
       </button>
     | None => React.null
     }}
  </div>;
};
