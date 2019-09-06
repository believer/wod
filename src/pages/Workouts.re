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
      "mt-10 mb-20",
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
      "mb-10 md:flex justify-between items-center",
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

module Filter = {
  let workoutType = (workoutType, wodType) =>
    switch (workoutType, wodType) {
    | (Some(EMOM), `AltEMOM(_))
    | (Some(EMOM), `EMOM(_)) => true
    | (Some(EMOM), _) => false
    | (Some(AMRAP), `AMRAP) => true
    | (Some(AMRAP), _) => false
    | (Some(ForTime), `ForTime) => true
    | (Some(ForTime), _) => false
    | (None, _) => true
    };

  let category = (stateCategory, category) =>
    switch (stateCategory, category) {
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
    };
};

[@react.component]
let make = (~query) => {
  let lastVisit = Cookie.getAsString("wod-last-visit");

  Cookie.setStringConfig(
    "wod-last-visit",
    Js.Date.make() |> Js.Date.toISOString,
    Cookie.Config.make(~expires=3650, ()),
  );

  let (state, dispatch) =
    ReactUpdate.useReducer(
      {category: None, workoutType: None, system: Metric, query: None},
      (action, state) =>
      switch (action) {
      | SetCategory(category) => Update({...state, category})
      | SetWorkoutType(workoutType) => Update({...state, workoutType})
      | SetSystem(system) =>
        UpdateWithSideEffects(
          {...state, system},
          _ => {
            Storage.set("wod-system", Settings.toString(system)) |> ignore;

            None;
          },
        )
      | UpdateQuery(query) => Update({...state, query})
      }
    );

  React.useEffect0(() => {
    Js.Promise.(
      Storage.get("wod-system")
      |> then_(value => {
           dispatch(SetSystem(Settings.fromString(value)));
           resolve();
         })
      |> ignore
    );

    None;
  });

  React.useEffect1(
    () => {
      switch (query) {
      | None =>
        dispatch(SetCategory(None));
        dispatch(UpdateQuery(None));
      | Some(q) =>
        switch (q->Js.String.toLowerCase) {
        | "girl"
        | "the girls"
        | "girls" =>
          dispatch(SetCategory(Some(Girl)));
          dispatch(UpdateQuery(None));
        | "hero" =>
          dispatch(SetCategory(Some(Hero)));
          dispatch(UpdateQuery(None));
        | _ => dispatch(UpdateQuery(Some(q)))
        }
      };

      None;
    },
    [|query|],
  );

  let wods =
    Wods.wods
    ->Belt.List.keep(({name}) => Search.filter(state.query, name))
    ->Belt.List.keep(({wodType}) =>
        Filter.workoutType(state.workoutType, wodType)
      )
    ->Belt.List.keep(({category: wc}) =>
        Filter.category(state.category, wc)
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
      <div className=Style.filters>
        <div>
          <div className="mb-2">
            {workoutTypes
             ->Belt.List.mapWithIndex((i, pill) =>
                 <Pill
                   className={
                     i < workoutTypes->Belt.List.length - 1 ? "mr-4" : ""
                   }
                   key={pill.label}
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
                   key={pill.label}
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
           ->Belt.List.map(wod => <Workout key={wod.id} lastVisit wod />)
           ->Belt.List.toArray
           ->React.array
         }}
      </div>
    </main>
  </Settings.Context.Provider>;
};
