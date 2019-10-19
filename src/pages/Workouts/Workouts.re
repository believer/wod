module Filter = {
  let workoutType = (workoutType: option(Route.workoutType), wodType) =>
    switch (workoutType, wodType) {
    | (Some(EMOM), `AltEMOM(_))
    | (Some(EMOM), `E90(_))
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
    | (Some(Strength), Some(`Strength)) => true
    | (Some(Strength), _) => false
    | (Some(Mayhem), Some(`Mayhem)) => true
    | (Some(Mayhem), _) => false
    | (None, Some(_))
    | (None, None) => true
    };
};

[@react.component]
let make = (~query, ~workoutCategory, ~workoutType, ~resetQuery) => {
  let lastVisit = Cookie.getAsString("wod-last-visit");
  let (system, setSystem) =
    Storage.useStorage(
      ~key="wod-system",
      ~parser=Settings.fromString,
      ~initialValue=Settings.Metric,
    );
  let (globalWodVersion, setGlobalWodVersion) =
    Storage.useStorage(
      ~key="wod-wod-version",
      ~parser=Workout.fromString,
      ~initialValue=Workout.RX,
    );

  Cookie.setStringConfig(
    "wod-last-visit",
    Js.Date.make() |> Js.Date.toISOString,
    Cookie.Config.make(~expires=3650, ()),
  );

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

  let filteredWods =
    Belt.List.(
      Wods.wods
      ->keep(({name}) =>
          Search.filter(
            noQuery |> List.exists(q => q === query) ? None : query,
            name,
          )
        )
      ->keep(({wodType}) => Filter.workoutType(workoutType, wodType))
      ->keep(({category}) => Filter.category(workoutCategory, category))
    );

  let filteredWodsLength = Belt.List.length(filteredWods);

  <Settings.Context.Provider value={system: system}>
    <main className="mt-10 mb-20 grid grid-template-main">
      <div
        className="mb-10 md:flex justify-between items-center grid-column-main">
        <WorkoutFilters workoutCategory workoutType />
        <WorkoutSettings
          globalWodVersion
          setGlobalWodVersion
          setSystem
          system
        />
      </div>
      {switch (query, workoutType, workoutCategory) {
       | (None, None, None) => React.null
       | (_, _, _) =>
         <div className="mb-10 grid-column-main">
           <Alert
             onClick={_ => {
               Route.go(Home((None, None)));
               resetQuery();
             }}
             text={
               "Filtered **"
               ++ filteredWodsLength->string_of_int
               ++ "** workouts"
             }
           />
         </div>
       }}
      <div className="grid grid-column-main grid-gap grid-template-cards">
        {switch (filteredWodsLength) {
         | 0 =>
           <div
             className="bg-white text-center p-8 rounded text-gray-600 grid-column-bleed">
             {React.string(
                {j|I don't have any WODs with this combination yet 💪|j},
              )}
           </div>
         | _ =>
           filteredWods
           ->Belt.List.reverse
           ->Belt.List.map(wod =>
               <Workout
                 key={wod.id->CUID.toString}
                 globalWodVersion
                 lastVisit
                 wod
               />
             )
           ->Belt.List.toArray
           ->React.array
         }}
      </div>
      <a
        className="text-center text-gray-500 mt-10 grid-column-main"
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
