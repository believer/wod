module Style = {
  open Css;

  let wrap =
    merge([
      "mt-16",
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

  let inner =
    merge([
      "flex items-center justify-between border-b pb-4 flex-wrap sm:h-16 ",
      style([gridColumn(3, 4)]),
    ]);
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (query, setQuery) = React.useState(() => None);
  let path = Route.fromPath(url.path);

  <div>
    {switch (path) {
     | Glossary
     | Home((_, _)) =>
       <header className=Style.wrap>
         <div className=Style.inner>
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
  </div>;
};
