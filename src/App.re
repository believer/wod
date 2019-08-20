type state = {
  category: option(Category.t),
  filter: option(WodType.t),
  system: Settings.system,
};

type action =
  | SetCategory(option(Category.t))
  | SetFilter(option(WodType.t))
  | SetSystem(Settings.system);

module Style = {
  open Css;

  let wrap =
    merge([
      "my-20",
      style([
        display(`grid),
        gridTemplateColumns([
          `px(20),
          `fr(1.0),
          `minmax((`px(310), `px(1400))),
          `fr(1.0),
          `px(20),
        ]),
      ]),
    ]);

  let filters =
    merge([
      "mb-8 flex justify-between items-center",
      style([gridColumn(3, 4)]),
    ]);

  let cards =
    style([
      display(`grid),
      gridColumn(3, 4),
      gridGap(`px(32)),
      media("(max-width: 480px)", [gridTemplateColumns([`fr(1.0)])]),
      unsafe("gridTemplateColumns", "repeat(auto-fill, minmax(310px, 1fr))"),
    ]);
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetCategory(c) => {...state, category: c}
        | SetFilter(f) => {...state, filter: f}
        | SetSystem(w) => {...state, system: w}
        },
      {category: None, filter: None, system: Metric},
    );

  <Settings.Provider value={Settings.system: state.system}>
    <main className=Style.wrap>
      <div className=Style.filters>
        <div>
          <div className="mb-2">
            <Pill
              className="mr-4"
              onClick={_ => dispatch(SetFilter(None))}
              selected={Belt.Option.isNone(state.filter)}>
              {React.string("All")}
            </Pill>
            <Pill
              className="mr-4"
              onClick={_ => dispatch(SetFilter(Some(`ForTime)))}
              selected={state.filter === Some(`ForTime)}>
              {React.string("For time")}
            </Pill>
            <Pill
              onClick={_ => dispatch(SetFilter(Some(`AMRAP)))}
              selected={state.filter === Some(`AMRAP)}>
              {React.string("AMRAP")}
            </Pill>
          </div>
          <div>
            <Pill
              className="mr-4"
              onClick={_ => dispatch(SetCategory(None))}
              selected={Belt.Option.isNone(state.category)}>
              {React.string("All")}
            </Pill>
            <Pill
              className="mr-4"
              onClick={_ => dispatch(SetCategory(Some(`Hero)))}
              selected={state.category == Some(`Hero)}>
              {React.string("Hero")}
            </Pill>
            <Pill
              onClick={_ =>
                dispatch(SetCategory(Some(`Wodapalooza(2019))))
              }
              selected={state.category == Some(`Wodapalooza(2019))}>
              {React.string("Wodapalooza 2019")}
            </Pill>
          </div>
        </div>
        <div>
          {switch (state.system) {
           | Metric =>
             <Button onClick={_ => dispatch(SetSystem(Imperial))}>
               {React.string("lbs")}
             </Button>
           | Imperial =>
             <Button onClick={_ => dispatch(SetSystem(Metric))}>
               {React.string("kg")}
             </Button>
           }}
        </div>
      </div>
      <div className=Style.cards>
        {Wod.wods
         ->Belt.List.keep(wod =>
             switch (state.filter) {
             | Some(f) => f === wod.wodType
             | None => true
             }
           )
         ->Belt.List.keep(wod =>
             switch (state.category, wod.category) {
             | (Some(c), Some(wc)) => c == wc
             | (Some(_), None) => false
             | (None, Some(_))
             | (None, None) => true
             }
           )
         ->Belt.List.map(wod =>
             <div className="bg-white rounded shadow-lg p-6" key={wod.id}>
               <header className="flex items-center justify-between">
                 <div className="font-bold">
                   {switch (wod.name) {
                    | Some(name) => React.string(name)
                    | None => React.string(WodType.toString(wod.wodType))
                    }}
                   {switch (wod.timeCap) {
                    | Some(t) =>
                      " " ++ t->string_of_int ++ " min" |> React.string
                    | None => React.null
                    }}
                 </div>
                 {switch (wod.category) {
                  | Some(c) =>
                    switch (c) {
                    | `Hero =>
                      <Pill background=`Red> {React.string("Hero")} </Pill>
                    | `Girl => <Pill> {React.string("Girl")} </Pill>
                    | `Wodapalooza(year) =>
                      <Pill>
                        {React.string("Wodapalooza " ++ year->string_of_int)}
                      </Pill>
                    }
                  | None => React.null
                  }}
               </header>
               {switch (wod.rounds) {
                | Some(r) =>
                  <div> {r->string_of_int ++ " rounds" |> React.string} </div>
                | None => React.null
                }}
               <ul className="text-gray-700 mt-4">
                 {wod.parts
                  ->Belt.List.mapWithIndex((i, part) =>
                      <li key={i->string_of_int}>
                        <Exercise.Unit reps={part.reps} />
                        <Exercise.Equipment equipment={part.equipment} />
                        {React.string(
                           " " ++ Wod.Exercise.toString(part.exercise) ++ " ",
                         )}
                        <Exercise.Weight weight={part.weight} />
                      </li>
                    )
                  ->Belt.List.toArray
                  ->React.array}
               </ul>
               {switch (wod.description) {
                | Some(desc) =>
                  <div className="mt-4 text-xs text-gray-500">
                    {React.string(desc)}
                  </div>
                | None => React.null
                }}
             </div>
           )
         ->Belt.List.toArray
         ->React.array}
      </div>
    </main>
  </Settings.Provider>;
};
