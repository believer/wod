type t =
  | RX
  | Scaled

let fromString = str =>
  switch str {
  | "scaled" => Scaled
  | _ => RX
  }

let toString = value =>
  switch value {
  | RX => "rx"
  | Scaled => "scaled"
  }

module NewTag = {
  type t =
    | New
    | Old

  let tagState = (lastVisit, createdAt) =>
    createdAt->Js.Date.fromString->Js.Date.getTime > lastVisit->Js.Date.fromString->Js.Date.getTime
      ? New
      : Old

  @react.component
  let make = (~lastVisit, ~createdAt) => {
    switch lastVisit {
    | Some(last) =>
      switch tagState(last, createdAt) {
      | New =>
        <div
          className="mb-4 uppercase rounded bg-green-200 text-xs text-green-700 inline-block px-2 py-1">
          {React.string("New")}
        </div>
      | Old => React.null
      }
    | None => React.null
    }
  }
}

module Header = {
  @react.component
  let make = (~wod: Wod.t) => {
    <header className="flex items-center justify-between">
      <div className="font-bold">
        {switch wod.name {
        | Some(name) => name
        | None => WodType.toString(wod.wodType)
        } |> React.string}
        {switch (wod.timeCap, wod.wodType, wod.name) {
        | (Some(t), #AMRAP, None) =>
          t->string_of_int ++ " min" |> Utils.padStartWithSpace |> React.string
        | (Some(_), _, _)
        | (None, _, _) => React.null
        }}
      </div>
    </header>
  }
}

module AltEMOM = {
  @react.component
  let make = (~wod: Wod.t) => {
    switch (wod.wodType, wod.name) {
    | (#AltEMOM(min), _) =>
      <div className="text-sm text-gray-500">
        {(min / wod.parts->Belt.Array.length)->string_of_int ++ " of each" |> React.string}
      </div>
    | _ => React.null
    }
  }
}

module Rounds = {
  @react.component
  let make = (~rounds) => {
    switch rounds {
    | Some(r) =>
      <div className="text-sm text-gray-500">
        {r->string_of_int ++ " rounds for time of:" |> React.string}
      </div>
    | None => React.null
    }
  }
}

module RepScheme = {
  @react.component
  let make = (~repScheme) => {
    switch repScheme {
    | Some(scheme) =>
      <div className="mt-4 text-gray-700">
        {scheme->Belt.Array.reduceWithIndex("", (acc, curr, i) =>
          switch i {
          | 0 => curr->string_of_int
          | _ => acc ++ "-" ++ curr->string_of_int
          }
        ) ++ " reps for time of:" |> React.string}
      </div>
    | None => React.null
    }
  }
}

module NamedAMRAP = {
  module Element = {
    @react.component
    let make = (~title, ~time) => {
      <div className="mt-4 text-gray-700 text-sm">
        <span className="font-semibold"> {React.string(title)} </span>
        {time->string_of_int ++ " min" |> Utils.padStartWithSpace |> React.string}
      </div>
    }
  }

  @react.component
  let make = (~wod) => {
    let {timeCap, wodType, name}: Wod.t = wod

    switch (timeCap, wodType, name) {
    | (Some(time), #AMRAP, Some(_)) => <Element title="AMRAP:" time />
    | (_, #EMOM(time), Some(_)) => <Element title="EMOM:" time />
    | (_, #E90(minutes) as t, Some(_)) =>
      <div className="mt-4 text-gray-700 text-sm">
        <span className="font-semibold"> {WodType.toString(t) ++ ":" |> React.string} </span>
        {minutes->string_of_int ++ " min" |> Utils.padStartWithSpace |> React.string}
        {"(" ++ WodType.toRounds(t)->string_of_int ++ " sets)"
        |> Utils.padStartWithSpace
        |> React.string}
      </div>
    | (Some(_), _, _)
    | (None, _, _) => React.null
    }
  }
}

module BuyInOut = {
  @react.component
  let make = (~buyInOut: option<WodPart.t>, ~title) => {
    switch buyInOut {
    | Some({reps, equipment, weight, exercise}) =>
      <div className="mt-4">
        <strong> {React.string(title)} </strong>
        <WodParts.Unit reps />
        <WodParts.Equipment equipment />
        {Exercise.toString(exercise) |> React.string}
        <WodParts.Weight weight />
      </div>
    | None => React.null
    }
  }
}

module WodItem = {
  @react.component
  let make = (~parts: array<WodPart.t>, ~wod: Wod.t) => {
    parts
    ->Belt.Array.map(({id, reps, equipment, exercise, weight}) =>
      <li key={id->CUID.toString}>
        <WodParts.Unit reps />
        <WodParts.Equipment equipment />
        {switch (wod.repScheme, reps, exercise) {
        | (Some(_), _, e) =>
          switch e {
          | #BurpeeOverRower
          | #Row
          | #Run
          | #SkiErg =>
            e->Exercise.toString->Utils.capitalizeFirst
          | _ => e->Exercise.toString->Utils.capitalizeFirst->Utils.pluralize
          }
        | (None, #Num(v), #ToesToBar as e) when v > 1 => e->Exercise.toString
        | (None, #Span(#Num(v), _), e)
        | (None, #Span(#OneSide(v, _), _), e)
        | (None, #OneSide(v, _), e)
        | (None, #Increasing(v), e)
        | (None, #Num(v), e) when v > 1 =>
          e->Exercise.toString->Utils.pluralize
        | (None, _, e) => e->Exercise.toString
        }
        |> Utils.padStartWithSpace
        |> Utils.padEndWithSpace
        |> React.string}
        <WodParts.Weight weight />
      </li>
    )
    ->React.array
  }
}

module TimeCap = {
  @react.component
  let make = (~wod: Wod.t) => {
    switch (wod.timeCap, wod.wodType) {
    | (Some(t), #ForTime) =>
      <div className="mt-4 text-sm text-gray-700">
        <span className="font-semibold"> {"Time cap:"->Utils.padEndWithSpace->React.string} </span>
        {t->string_of_int ++ " min" |> React.string}
      </div>
    | (Some(t), #ForDistance) =>
      <div className="mt-4 text-sm">
        {React.string("For max meters")}
        <div className="text-gray-700">
          <span className="font-semibold">
            {"Time cap:"->Utils.padEndWithSpace->React.string}
          </span>
          {t->string_of_int ++ " min" |> React.string}
        </div>
      </div>
    | (Some(_), #AltEMOM(_))
    | (Some(_), #EMOM(_))
    | (Some(_), #AMRAP)
    | (Some(_), #E90(_))
    | (None, _) => React.null
    }
  }
}

@react.component
let make = (~lastVisit, ~wod: Wod.t, ~globalWodVersion) => {
  let (wodVersion, setWodVersion) = React.useState(() => RX)

  let (buyIn, buyOut) = switch wod.buyInOut {
  | Some((Some(buyIn), Some(buyOut))) => (Some(buyIn), Some(buyOut))
  | Some((Some(buyIn), None)) => (Some(buyIn), None)
  | Some((None, Some(buyOut))) => (None, Some(buyOut))
  | Some((None, _))
  | None => (None, None)
  }

  React.useEffect2(() => {
    switch wod.scaledParts {
    | Some(_) => setWodVersion(_ => globalWodVersion)
    | None => ()
    }

    None
  }, (globalWodVersion, wod))

  <div className="bg-white rounded shadow-lg flex flex-col justify-between">
    <div className="p-6">
      <NewTag createdAt={wod.createdAt} lastVisit />
      <Header wod />
      <AltEMOM wod />
      <Rounds rounds={wod.rounds} />
      <RepScheme repScheme={wod.repScheme} />
      <NamedAMRAP wod />
      <BuyInOut buyInOut=buyIn title="Buy-in: " />
      <ul className="text-gray-700 mt-4">
        {switch wodVersion {
        | RX => <WodItem parts={wod.parts} wod />
        | Scaled => <WodItem parts={wod.scaledParts->Belt.Option.getWithDefault([])} wod />
        }}
      </ul>
      <BuyInOut buyInOut=buyOut title="Buy-out: " />
      <TimeCap wod />
      {switch (wod.description, wodVersion) {
      | (Some((Some(text), _)), RX)
      | (Some((_, Some(text))), Scaled)
      | (Some((Some(text), None)), Scaled) =>
        <Markdown className="mt-4 text-xs text-gray-500" text />
      | (Some((None, Some(_))), RX)
      | (Some((None, None)), _)
      | (None, _) => React.null
      }}
      {switch wod.externalLink {
      | Some((name, href)) => <Router.ExternalLink href> {React.string(name)} </Router.ExternalLink>
      | None => React.null
      }}
      <div className="mt-4">
        {switch wod.category {
        | Some(c) =>
          switch c {
          | #Hero =>
            <Pill color=#Green onClick={_ => Route.go(Home((None, Some(Hero))))}>
              {React.string("Hero")}
            </Pill>
          | #Girl =>
            <Pill color=#Pink onClick={_ => Route.go(Home((None, Some(Girl))))}>
              {React.string("The Girls")}
            </Pill>
          | #Wodapalooza(year) =>
            <Pill onClick={_ => Route.go(Home((None, Some(WZA))))}>
              {React.string("Wodapalooza " ++ year->string_of_int)}
            </Pill>
          | #Open(year) =>
            <Pill onClick={_ => Route.go(Home((None, Some(Open))))}>
              {React.string("Open " ++ year->string_of_int)}
            </Pill>
          | #Strength =>
            <Pill color=#Purple onClick={_ => Route.go(Home((None, Some(Strength))))}>
              {React.string("Strength")}
            </Pill>
          | #Mayhem =>
            <Pill color=#Blue onClick={_ => Route.go(Home((None, Some(Mayhem))))}>
              {React.string("Mayhem")}
            </Pill>
          }
        | None => React.null
        }}
      </div>
    </div>
    {switch wod.scaledParts {
    | Some(_) =>
      <button
        className="bg-gray-200 rounded-b py-3 text-sm text-gray-600 font-semibold hover:bg-gray-300"
        onClick={_ => setWodVersion(_ => wodVersion === RX ? Scaled : RX)}
        type_="button">
        {switch wodVersion {
        | RX => "Switch to scaled"
        | Scaled => "Switch to RX"
        } |> React.string}
      </button>
    | None => React.null
    }}
  </div>
}
