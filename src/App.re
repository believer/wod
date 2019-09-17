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
             <Router.NavLink
               activeClassName="text-blue-500" className="mr-8" href="/">
               {React.string("Workouts")}
             </Router.NavLink>
             <Router.NavLink
               activeClassName="text-blue-500" className="" href="/glossary">
               {React.string("Glossary")}
             </Router.NavLink>
           </div>
           {switch (path) {
            | Home((_, _)) =>
              <Search
                onChange={e =>
                  switch (e->ReactEvent.Form.target##value) {
                  | "" => setQuery(_ => None)
                  | v => setQuery(_ => Some(v))
                  }
                }
                query
              />
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
