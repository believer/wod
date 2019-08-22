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
      "mb-8 md:flex justify-between items-center",
      style([gridColumn(3, 4)]),
    ]);

  let emptyState =
    merge([
      "bg-white text-center p-8 rounded text-gray-600",
      style([gridColumn(-1, 1)]),
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
  let wods =
    Wod.wods
    ->Belt.List.keep(wod =>
        switch (state.filter) {
        | Some(`EMOM(_)) => Pervasives.compare(wod.wodType, `EMOM(0)) === 1
        | Some(f) => f == wod.wodType
        | None => true
        }
      )
    ->Belt.List.keep(wod =>
        switch (state.category, wod.category) {
        | (Some(c), Some(wc)) => Pervasives.compare(c, wc) === 0
        | (Some(_), None) => false
        | (None, Some(_))
        | (None, None) => true
        }
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
              selected={state.filter == Some(`ForTime)}>
              {React.string("For time")}
            </Pill>
            <Pill
              className="mr-4"
              onClick={_ => dispatch(SetFilter(Some(`EMOM(0))))}
              selected={state.filter == Some(`EMOM(0))}>
              {React.string("EMOM")}
            </Pill>
            <Pill
              onClick={_ => dispatch(SetFilter(Some(`AMRAP)))}
              selected={state.filter == Some(`AMRAP)}>
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
              className="mr-4"
              onClick={_ => dispatch(SetCategory(Some(`Girl)))}
              selected={state.category == Some(`Girl)}>
              {React.string("The Girls")}
            </Pill>
            <Pill
              className="mr-4"
              onClick={_ =>
                dispatch(SetCategory(Some(`Wodapalooza(2019))))
              }
              selected={state.category == Some(`Wodapalooza(2019))}>
              {React.string("Wodapalooza 2019")}
            </Pill>
            <Pill
              onClick={_ =>
                dispatch(SetCategory(Some(`Open((18, 2, `Scaled)))))
              }
              selected={state.category == Some(`Open((18, 2, `Scaled)))}>
              {React.string("Open 2018")}
            </Pill>
          </div>
        </div>
        <div className="flex items-center mt-4 md:mt-0">
          {switch (state.system) {
           | Metric =>
             <Button onClick={_ => dispatch(SetSystem(Imperial))}>
               {React.string("Imperial")}
             </Button>
           | Imperial =>
             <Button onClick={_ => dispatch(SetSystem(Metric))}>
               {React.string("Metric")}
             </Button>
           }}
          <a
            className="ml-4 text-gray-500 hover:text-gray-700"
            href="https://github.com/believer/wod">
            <svg
              className="fill-current w-5 h-5"
              xmlns="http://www.w3.org/2000/svg"
              viewBox="0 0 20 20">
              <path
                d="M10 0a10 10 0 0 0-3.16 19.49c.5.1.68-.22.68-.48l-.01-1.7c-2.78.6-3.37-1.34-3.37-1.34-.46-1.16-1.11-1.47-1.11-1.47-.9-.62.07-.6.07-.6 1 .07 1.53 1.03 1.53 1.03.9 1.52 2.34 1.08 2.91.83.1-.65.35-1.09.63-1.34-2.22-.25-4.55-1.11-4.55-4.94 0-1.1.39-1.99 1.03-2.69a3.6 3.6 0 0 1 .1-2.64s.84-.27 2.75 1.02a9.58 9.58 0 0 1 5 0c1.91-1.3 2.75-1.02 2.75-1.02.55 1.37.2 2.4.1 2.64.64.7 1.03 1.6 1.03 2.69 0 3.84-2.34 4.68-4.57 4.93.36.31.68.92.68 1.85l-.01 2.75c0 .26.18.58.69.48A10 10 0 0 0 10 0"
              />
            </svg>
          </a>
        </div>
      </div>
      <div className=Style.cards>
        {switch (wods->Belt.List.length) {
         | 0 =>
           <div className=Style.emptyState>
             {React.string(
                {j|I don't have any WODs with this combination yet 💪|j},
              )}
           </div>
         | _ =>
           wods
           ->Belt.List.reverse
           ->Belt.List.map(wod =>
               <div className="bg-white rounded shadow-lg p-6" key={wod.id}>
                 <header className="flex items-center justify-between">
                   <div className="font-bold">
                     {switch (wod.name) {
                      | Some(name) => React.string(name)
                      | None => React.string(WodType.toString(wod.wodType))
                      }}
                   </div>
                   {switch (wod.category) {
                    | Some(c) =>
                      switch (c) {
                      | `Hero =>
                        <Pill background=`Green>
                          {React.string("Hero")}
                        </Pill>
                      | `Girl =>
                        <Pill background=`Pink>
                          {React.string("The Girls")}
                        </Pill>
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
                               "Open "
                               ++ year->string_of_int
                               ++ "."
                               ++ num->string_of_int,
                             )}
                          </Pill>
                        }
                      }
                    | None => React.null
                    }}
                 </header>
                 {switch (wod.wodType) {
                  | `AltEMOM(min) =>
                    <div className="text-sm text-gray-500">
                      {""
                       ++ (min / wod.parts->Belt.List.length)->string_of_int
                       ++ " of each"
                       |> React.string}
                    </div>
                  | _ => React.null
                  }}
                 {switch (wod.rounds) {
                  | Some(r) =>
                    <div className="text-sm text-gray-500">
                      {r->string_of_int ++ " rounds" |> React.string}
                    </div>
                  | None => React.null
                  }}
                 {switch (wod.repScheme) {
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
                  }}
                 <ul className="text-gray-700 mt-4">
                   {wod.parts
                    ->Belt.List.mapWithIndex((i, part) =>
                        <li key={i->string_of_int}>
                          <Exercise.Unit reps={part.reps} />
                          <Exercise.Equipment equipment={part.equipment} />
                          {" "
                           ++ (
                             switch (wod.repScheme) {
                             | Some(_) =>
                               part.exercise
                               ->Wod.Exercise.toString
                               ->Utils.capitalizeFirst
                             | None => Wod.Exercise.toString(part.exercise)
                             }
                           )
                           ++ " "
                           |> React.string}
                          <Exercise.Weight weight={part.weight} />
                        </li>
                      )
                    ->Belt.List.toArray
                    ->React.array}
                 </ul>
                 {switch (wod.timeCap) {
                  | Some(t) =>
                    <div className="mt-4 text-sm text-gray-700">
                      <span className="font-semibold">
                        {React.string("Time cap:")}
                      </span>
                      {" " ++ t->string_of_int ++ " min" |> React.string}
                    </div>
                  | None => React.null
                  }}
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
           ->React.array
         }}
      </div>
    </main>
  </Settings.Provider>;
};
