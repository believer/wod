[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (query, setQuery) = React.useState(() => None);
  let path = Route.fromPath(url.path);

  <>
    {switch (path) {
     | Glossary
     | Home((_, _)) =>
       <header className="mt-16 grid grid-template-main">
         <div
           className="flex items-center justify-between border-b pb-4 flex-wrap
           sm:h-16 grid-column-main">
           <div>
             <Router.NavLink className="mr-8" to_={Route.Home((None, None))}>
               {React.string("Workouts")}
             </Router.NavLink>
             <Router.NavLink className="" to_=Route.Glossary>
               {React.string("Glossary")}
             </Router.NavLink>
           </div>
           {switch (path) {
            | Home((_, _)) =>
              <Search onChange={v => setQuery(_ => v)} query />
            | Glossary
            | NotFoundRoute => React.null
            }}
         </div>
       </header>
     | NotFoundRoute => React.null
     }}
    {switch (path) {
     | Home((workoutType, workoutCategory)) =>
       <Workouts
         query
         resetQuery={_ => setQuery(_ => None)}
         workoutCategory
         workoutType
       />
     | Glossary => <Glossary />
     | NotFoundRoute => <FourOFour />
     }}
  </>;
};
