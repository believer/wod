type workoutType =
  | EMOM
  | AMRAP
  | ForTime;

type workoutCategory =
  | Hero
  | Girl
  | WZA
  | Open;

type state = {
  category: option(workoutCategory),
  workoutType: option(workoutType),
  query: option(string),
  system: Settings.system,
};

type action =
  | UpdateQuery(option(string))
  | SetCategory(option(workoutCategory))
  | SetWorkoutType(option(workoutType))
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
  let lastVisit = Cookie.getAsString("lastVisit");

  Cookie.setStringConfig(
    "lastVisit",
    Js.Date.make() |> Js.Date.toISOString,
    Cookie.Config.make(~expires=3650, ()),
  );

  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetCategory(category) => {...state, category}
        | SetWorkoutType(workoutType) => {...state, workoutType}
        | SetSystem(system) => {...state, system}
        | UpdateQuery(query) => {...state, query}
        },
      {category: None, workoutType: None, system: Metric, query: None},
    );

  let wods =
    Wod.wods
    ->Belt.List.keep(({name}) => Search.filter(state.query, name))
    ->Belt.List.keep(wod =>
        switch (state.workoutType, wod.wodType) {
        | (Some(EMOM), `AltEMOM(_))
        | (Some(EMOM), `EMOM(_)) => true
        | (Some(EMOM), _) => false
        | (Some(AMRAP), `AMRAP) => true
        | (Some(AMRAP), _) => false
        | (Some(ForTime), `ForTime) => true
        | (Some(ForTime), _) => false
        | (None, _) => true
        }
      )
    ->Belt.List.keep(wod =>
        switch (state.category, wod.category) {
        | (Some(WZA), Some(`Wodapalooza(_))) => true
        | (Some(WZA), _) => false
        | (Some(Open), Some(`Open(_))) => true
        | (Some(Open), _) => false
        | (Some(Girl), Some(`Girl)) => true
        | (Some(Girl), _) => false
        | (Some(Hero), Some(`Hero)) => true
        | (Some(Hero), _) => false
        | (None, Some(_))
        | (None, None) => true
        }
      );

  let workoutTypes =
    Pill.[
      Item.make(~label="All", ()),
      Item.make(~value=Some(ForTime), ~label="For time", ()),
      Item.make(~value=Some(EMOM), ~label="EMOM", ()),
      Item.make(~value=Some(AMRAP), ~label="AMRAP", ()),
    ];

  let workoutCategories =
    Pill.[
      Item.make(~label="All", ()),
      Item.make(~value=Some(Hero), ~label="Hero", ()),
      Item.make(~value=Some(Girl), ~label="The Girls", ()),
      Item.make(~value=Some(WZA), ~label="Wodapalooza", ()),
      Item.make(~value=Some(Open), ~label="Open", ()),
    ];

  <Settings.Context.Provider value={Settings.system: state.system}>
    <main className=Style.wrap>
      <Search
        onChange={e =>
          switch (e->ReactEvent.Form.target##value) {
          | "" => dispatch(UpdateQuery(None))
          | v =>
            switch (v->Js.String.toLowerCase) {
            | "the girls"
            | "girls" =>
              dispatch(SetCategory(Some(Girl)));
              dispatch(UpdateQuery(None));
            | "hero" =>
              dispatch(SetCategory(Some(Hero)));
              dispatch(UpdateQuery(None));
            | _ => dispatch(UpdateQuery(Some(v)))
            }
          }
        }
        query={state.query}
      />
      <div className=Style.filters>
        <div>
          <div className="mb-2">
            {workoutTypes
             ->Belt.List.mapWithIndex((i, pill) =>
                 <Pill
                   className={
                     i < workoutTypes->Belt.List.length - 1 ? "mr-4" : ""
                   }
                   onClick={_ => dispatch(SetWorkoutType(pill.value))}
                   selected={
                     switch (pill.value) {
                     | None => Belt.Option.isNone(state.workoutType)
                     | Some(value) => state.workoutType === Some(value)
                     }
                   }>
                   {React.string(pill.label)}
                 </Pill>
               )
             ->Belt.List.toArray
             ->React.array}
          </div>
          <div>
            {workoutCategories
             ->Belt.List.mapWithIndex((i, pill) =>
                 <Pill
                   className={
                     i < workoutCategories->Belt.List.length - 1 ? "mr-4" : ""
                   }
                   onClick={_ => dispatch(SetCategory(pill.value))}
                   selected={
                     switch (pill.value) {
                     | None => Belt.Option.isNone(state.category)
                     | Some(value) => state.category === Some(value)
                     }
                   }>
                   {React.string(pill.label)}
                 </Pill>
               )
             ->Belt.List.toArray
             ->React.array}
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
            <Icon name=`GitHub />
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
           ->Belt.List.map(wod => <Workout lastVisit wod />)
           ->Belt.List.toArray
           ->React.array
         }}
      </div>
    </main>
  </Settings.Context.Provider>;
};
