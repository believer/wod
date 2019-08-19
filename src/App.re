type state = {
  category: option(Wod.Category.t),
  filter: option(Wod.WodType.t),
};

type action =
  | SetCategory(option(Wod.Category.t))
  | SetFilter(option(Wod.WodType.t));

module Style = {
  open Css;

  let wrap =
    merge([
      "mt-20",
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

  let filters = merge(["mb-8", style([gridColumn(3, 4)])]);

  let cards =
    style([
      display(`grid),
      gridColumn(3, 4),
      gridGap(`px(32)),
      media("(max-width: 480px)", [gridTemplateColumns([`fr(1.0)])]),
      unsafe("grid-template-columns", "repeat(auto-fit, minmax(310px, 1fr))"),
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
        },
      {category: None, filter: None},
    );

  <main className=Style.wrap>
    <div className=Style.filters>
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
          selected={state.category === Some(`Hero)}>
          {React.string("Hero")}
        </Pill>
        <Pill
          onClick={_ => dispatch(SetCategory(Some(`Girl)))}
          selected={state.category === Some(`Girl)}>
          {React.string("The Girls")}
        </Pill>
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
       ->Belt.List.keep(wod => {
           Js.log2(state.category, wod.category);
           switch (state.category, wod.category) {
           | (Some(c), Some(wc)) => c === wc
           | (Some(_), None) => false
           | (None, Some(_))
           | (None, None) => true
           };
         })
       ->Belt.List.map(wod =>
           <div className="bg-white rounded shadow-lg p-6" key={wod.id}>
             <header className="flex items-center justify-between">
               <div className="font-bold">
                 {switch (wod.name) {
                  | Some(name) => React.string(name)
                  | None => React.string(Wod.WodType.toString(wod.wodType))
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
           </div>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
  </main>;
};
