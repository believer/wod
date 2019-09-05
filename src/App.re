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
      "flex items-center justify-between border-b pb-4 flex-wrap",
      style([gridColumn(3, 4)]),
    ]);
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (query, setQuery) = React.useState(() => None);

  <div>
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
        {switch (url.path) {
         | [] =>
           <Search
             onChange={e =>
               switch (e->ReactEvent.Form.target##value) {
               | "" => setQuery(_ => None)
               | v => setQuery(_ => Some(v))
               }
             }
             query
           />
         | _ => React.null
         }}
      </div>
    </header>
    {switch (url.path) {
     | [] => <Workouts query />
     | ["glossary"] => <Glossary />
     | _ => <FourOFour />
     }}
  </div>;
};
