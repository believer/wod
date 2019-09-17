[@react.component]
let make =
    (
      ~globalWodVersion: Workout.t,
      ~setGlobalWodVersion,
      ~setSystem,
      ~system: Settings.system,
    ) => {
  <div className="flex items-center mt-4 md:mt-0">
    <div className="mr-4">
      {switch (globalWodVersion) {
       | RX =>
         <Button
           onClick={_ => setGlobalWodVersion(Workout.toString(Scaled))}>
           {React.string("Scaled")}
         </Button>
       | Scaled =>
         <Button onClick={_ => setGlobalWodVersion(Workout.toString(RX))}>
           {React.string("RX")}
         </Button>
       }}
    </div>
    {switch (system) {
     | Metric =>
       <Button onClick={_ => setSystem(Settings.toString(Imperial))}>
         {React.string("Imperial")}
       </Button>
     | Imperial =>
       <Button onClick={_ => setSystem(Settings.toString(Metric))}>
         {React.string("Metric")}
       </Button>
     }}
  </div>;
};
