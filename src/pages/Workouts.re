type state = {
  globalWodVersion: Workout.t,
  system: Settings.system,
};

type action =
  | SetGlobalWodVersion(Workout.t)
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

  let alerts = merge(["mb-10", style([gridColumn(3, 4)])]);

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

  let versionNumber =
    merge(["text-center text-gray-500 mt-10", style([gridColumn(3, 4)])]);
};

module Filter = {
  let workoutType = (workoutType: option(Route.workoutType), wodType) =>
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

  let category = (stateCategory: option(Route.workoutCategory), category) =>
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
let make = (~query, ~workoutCategory, ~workoutType, ~resetQuery) => {
  let lastVisit = Cookie.getAsString("wod-last-visit");

  Cookie.setStringConfig(
    "wod-last-visit",
    Js.Date.make() |> Js.Date.toISOString,
    Cookie.Config.make(~expires=3650, ()),
  );

  let (state, dispatch) =
    ReactUpdate.useReducer(
      {system: Metric, globalWodVersion: RX}, (action, state) =>
      switch (action) {
      | SetGlobalWodVersion(globalWodVersion) =>
        UpdateWithSideEffects(
          {...state, globalWodVersion},
          _ => {
            Storage.set(
              "wod-wod-version",
              switch (globalWodVersion) {
              | RX => "rx"
              | Scaled => "scaled"
              },
            )
            |> ignore;

            None;
          },
        )
      | SetSystem(system) =>
        UpdateWithSideEffects(
          {...state, system},
          _ => {
            Storage.set("wod-system", Settings.toString(system)) |> ignore;

            None;
          },
        )
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

    Js.Promise.(
      Storage.get("wod-wod-version")
      |> then_(value => {
           dispatch(
             SetGlobalWodVersion(
               switch (value) {
               | "scaled" => Scaled
               | _ => RX
               },
             ),
           );
           resolve();
         })
      |> ignore
    );

    None;
  });

  let noQuery = [
    Some("girl"),
    Some("girls"),
    Some("the girls"),
    Some("hero"),
    Some("heroes"),
    Some("wza"),
    Some("wodapalooza"),
    Some("open"),
    Some("games"),
  ];

  React.useEffect1(
    () => {
      switch (query) {
      | None => ()
      | Some(q) =>
        switch (q->Js.String.toLowerCase) {
        | "girl"
        | "the girls"
        | "girls" => Route.go(Home((workoutType, Some(Girl))))
        | "hero"
        | "heroes" => Route.go(Home((workoutType, Some(Hero))))
        | "wza"
        | "wodapalooza" => Route.go(Home((workoutType, Some(WZA))))
        | "open"
        | "games" => Route.go(Home((workoutType, Some(Open))))
        | _ => ()
        }
      };

      None;
    },
    [|query|],
  );

  let wods =
    Wods.wods
    ->Belt.List.keep(({name}) =>
        Search.filter(
          noQuery |> List.exists(q => q === query) ? None : query,
          name,
        )
      )
    ->Belt.List.keep(({wodType}) =>
        Filter.workoutType(workoutType, wodType)
      )
    ->Belt.List.keep(({category: wc}) =>
        Filter.category(workoutCategory, wc)
      );

  let workoutTypes =
    Pill.[
      Item.make(~label="All", ()),
      Item.make(~value=Some(Route.ForTime), ~label="For time", ()),
      Item.make(~value=Some(Route.EMOM), ~label="EMOM", ()),
      Item.make(~value=Some(Route.AMRAP), ~label="AMRAP", ()),
    ];

  let workoutCategories =
    Pill.[
      Item.make(~label="All", ()),
      Item.make(~value=Some(Route.Hero), ~label="Hero", ()),
      Item.make(~value=Some(Route.Girl), ~label="The Girls", ()),
      Item.make(~value=Some(Route.WZA), ~label="Wodapalooza", ()),
      Item.make(~value=Some(Route.Open), ~label="Open", ()),
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
                   onClick={_ =>
                     Route.go(Home((pill.value, workoutCategory)))
                   }
                   selected={
                     switch (pill.value) {
                     | None => Belt.Option.isNone(workoutType)
                     | Some(value) => workoutType === Some(value)
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
                   onClick={_ => Route.go(Home((workoutType, pill.value)))}
                   selected={
                     switch (pill.value) {
                     | None => Belt.Option.isNone(workoutCategory)
                     | Some(value) => workoutCategory === Some(value)
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
          {switch (state.globalWodVersion) {
           | RX =>
             <Button
               className="mr-4"
               onClick={_ => dispatch(SetGlobalWodVersion(Scaled))}>
               {React.string("Scaled")}
             </Button>
           | Scaled =>
             <Button
               className="mr-4"
               onClick={_ => dispatch(SetGlobalWodVersion(RX))}>
               {React.string("RX")}
             </Button>
           }}
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
      {switch (query, workoutType, workoutCategory) {
       | (Some(_), _, _)
       | (None, Some(_), None)
       | (None, None, Some(_))
       | (None, Some(_), Some(_)) =>
         <div className=Style.alerts>
           <Alert
             onClick={_ => {
               Route.go(Home((None, None)));
               resetQuery();
             }}
             text={
               "Filtered **"
               ++ wods->Belt.List.length->string_of_int
               ++ "** workouts"
             }
           />
         </div>
       | (None, None, None) => React.null
       }}
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
               <Workout
                 key={wod.id->CUID.Generate.toString}
                 globalWodVersion={state.globalWodVersion}
                 lastVisit
                 wod
               />
             )
           ->Belt.List.toArray
           ->React.array
         }}
      </div>
      <a
        className=Style.versionNumber
        href="https://github.com/believer/wod/blob/master/CHANGELOG.md"
        target="_blank"
        rel="noreferrer noopener">
        {React.string(
           Wods.wods->Belt.List.length->string_of_int
           ++ " workouts - v"
           ++ Utils.version,
         )}
      </a>
    </main>
  </Settings.Context.Provider>;
};
