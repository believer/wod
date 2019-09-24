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
    Item.make(~value=Some(Route.Mayhem), ~label="Mayhem", ()),
    Item.make(~value=Some(Route.Strength), ~label="Strength", ()),
  ];

[@react.component]
let make = (~workoutCategory, ~workoutType) => {
  <div>
    <div className="mb-2">
      {workoutTypes
       ->Belt.List.map(pill =>
           <Pill
             key={pill.label}
             onClick={_ => Route.go(Home((pill.value, workoutCategory)))}
             selected={Pill.matchSelected(pill.value, workoutType)}>
             {React.string(pill.label)}
           </Pill>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
    <div>
      {workoutCategories
       ->Belt.List.map(pill =>
           <Pill
             key={pill.label}
             onClick={_ => Route.go(Home((workoutType, pill.value)))}
             selected={Pill.matchSelected(pill.value, workoutCategory)}>
             {React.string(pill.label)}
           </Pill>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
  </div>;
};
