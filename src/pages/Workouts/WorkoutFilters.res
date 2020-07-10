open Pill

let workoutTypes =
  list[
    Item.make(~label="All", ()),
    Item.make(~value=Some(Route.WodType.ForTime), ~label="For time", ()),
    Item.make(~value=Some(Route.WodType.EMOM), ~label="EMOM", ()),
    Item.make(~value=Some(Route.WodType.AMRAP), ~label="AMRAP", ()),
  ]

let workoutCategories =
  list[
    Item.make(~label="All", ()),
    Item.make(~value=Some(Route.WodCategory.Hero), ~label="Hero", ()),
    Item.make(~value=Some(Route.WodCategory.Girl), ~label="The Girls", ()),
    Item.make(~value=Some(Route.WodCategory.WZA), ~label="Wodapalooza", ()),
    Item.make(~value=Some(Route.WodCategory.Open), ~label="Open", ()),
    Item.make(~value=Some(Route.WodCategory.Mayhem), ~label="Mayhem", ()),
    Item.make(
      ~value=Some(Route.WodCategory.Strength),
      ~label="Strength",
      (),
    ),
  ]

@react.component
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
  </div>
}
