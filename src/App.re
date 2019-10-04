[@react.component]
let make = () => {
  let {login, authState}: Auth0Context.t = Auth0Context.useAuth();
  let url = ReasonReactRouter.useUrl();
  let (query, setQuery) = React.useState(() => None);
  let path = Route.fromPath(url.path);

  <>
    {switch (path) {
     | Glossary
     | Home((_, _)) =>
       <header className="mt-20 grid grid-template-main">
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
           <div className="flex items-center">
             {switch (path) {
              | Home((_, _)) =>
                <Search onChange={v => setQuery(_ => v)} query />
              | Glossary
              | NotFoundRoute => React.null
              }}
             {switch (authState) {
              | Authenticated({email}) =>
                <div className="h-10 w-10 ml-4"> <Gravatar email /> </div>
              | Authenticating
              | NotLoggedIn =>
                <button
                  className="bg-gray-300 text-gray-700 rounded px-4 py-2 ml-4"
                  onClick={_ => login()}
                  type_="button">
                  {React.string("Login")}
                </button>
              }}
           </div>
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
