type t =
  | RX
  | Scaled;

[@react.component]
let make = (~lastVisit, ~wod: Wod.t) => {
  let (wodVersion, setWodVersion) = React.useState(() => RX);

  <div
    className="bg-white rounded shadow-lg flex flex-col
               justify-between">
    <div className="p-6" key={wod.id}>
      {switch (lastVisit) {
       | Some(last) =>
         Js.Date.fromString(wod.createdAt)
         |> Js.Date.getTime > (Js.Date.fromString(last) |> Js.Date.getTime)
           ? <div
               className="mb-4 uppercase rounded bg-green-200 text-xs text-green-700
                        inline-block px-2 py-1">
               {React.string("New")}
             </div>
           : React.null
       | None => React.null
       }}
      <header className="flex items-center justify-between">
        <div className="font-bold">
          {switch (wod.name) {
           | Some(name) => React.string(name)
           | None => React.string(WodType.toString(wod.wodType))
           }}
          {switch (wod.timeCap, wod.wodType) {
           | (Some(t), `AMRAP) =>
             " " ++ t->string_of_int ++ " min" |> React.string
           | (Some(_), _)
           | (None, _) => React.null
           }}
        </div>
        {switch (wod.category) {
         | Some(c) =>
           switch (c) {
           | `Hero => <Pill background=`Green> {React.string("Hero")} </Pill>
           | `Girl =>
             <Pill background=`Pink> {React.string("The Girls")} </Pill>
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
                    "Open " ++ year->string_of_int ++ "." ++ num->string_of_int,
                  )}
               </Pill>
             }
           | `Mayhem => React.null
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
           {r->string_of_int ++ " rounds for time of:" |> React.string}
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
      {switch (wod.buyInOut) {
       | Some((Some(buyIn), _)) =>
         <div className="mt-4">
           <strong> {React.string("Buy-in: ")} </strong>
           <WodParts.Unit reps={buyIn.reps} />
           <WodParts.Equipment equipment={buyIn.equipment} />
           {" " ++ Exercise.toString(buyIn.exercise) ++ " " |> React.string}
           <WodParts.Weight weight={buyIn.weight} />
         </div>
       | Some((None, _))
       | None => React.null
       }}
      <ul className="text-gray-700 mt-4">
        {switch (wodVersion) {
         | RX =>
           wod.parts
           ->Belt.List.mapWithIndex((i, part) =>
               <li key={i->string_of_int}>
                 <WodParts.Unit reps={part.reps} />
                 <WodParts.Equipment equipment={part.equipment} />
                 {" "
                  ++ (
                    switch (wod.repScheme) {
                    | Some(_) =>
                      part.exercise->Exercise.toString->Utils.capitalizeFirst
                    | None => Exercise.toString(part.exercise)
                    }
                  )
                  ++ " "
                  |> React.string}
                 <WodParts.Weight weight={part.weight} />
               </li>
             )
           ->Belt.List.toArray
           ->React.array
         | Scaled =>
           wod.scaledParts
           ->Belt.Option.getWithDefault([])
           ->Belt.List.mapWithIndex((i, part) =>
               <li key={i->string_of_int}>
                 <WodParts.Unit reps={part.reps} />
                 <WodParts.Equipment equipment={part.equipment} />
                 {" "
                  ++ (
                    switch (wod.repScheme) {
                    | Some(_) =>
                      part.exercise->Exercise.toString->Utils.capitalizeFirst
                    | None => Exercise.toString(part.exercise)
                    }
                  )
                  ++ " "
                  |> React.string}
                 <WodParts.Weight weight={part.weight} />
               </li>
             )
           ->Belt.List.toArray
           ->React.array
         }}
      </ul>
      {switch (wod.buyInOut) {
       | Some((_, Some(buyOut))) =>
         <div className="mt-4">
           <strong> {React.string("Buy-out: ")} </strong>
           <WodParts.Unit reps={buyOut.reps} />
           <WodParts.Equipment equipment={buyOut.equipment} />
           {" " ++ Exercise.toString(buyOut.exercise) ++ " " |> React.string}
           <WodParts.Weight weight={buyOut.weight} />
         </div>
       | Some((_, None))
       | None => React.null
       }}
      {switch (wod.timeCap, wod.wodType) {
       | (Some(t), `ForTime) =>
         <div className="mt-4 text-sm text-gray-700">
           <span className="font-semibold">
             {React.string("Time cap:")}
           </span>
           {" " ++ t->string_of_int ++ " min" |> React.string}
         </div>
       | (Some(_), _)
       | (None, _) => React.null
       }}
      {switch (wod.description) {
       | Some(desc) =>
         <div
           className="mt-4 text-xs text-gray-500 markdown"
           dangerouslySetInnerHTML={"__html": Markdown.make(desc)}
         />
       | None => React.null
       }}
      {switch (wod.externalLink) {
       | Some((name, href)) =>
         <a
           className="text-blue-600 text-xs block mt-2"
           target="_blank"
           rel="noreferrer noopener"
           href>
           {React.string(name)}
         </a>
       | None => React.null
       }}
    </div>
    {switch (wod.scaledParts) {
     | Some(_) =>
       <button
         className="bg-gray-200 rounded-b py-3 text-sm text-gray-600
                   font-semibold hover:bg-gray-300"
         onClick={_ => setWodVersion(_ => wodVersion === RX ? Scaled : RX)}
         type_="button">
         {switch (wodVersion) {
          | RX => React.string("Switch to scaled")
          | Scaled => React.string("Switch to RX")
          }}
       </button>
     | None => React.null
     }}
  </div>;
};
