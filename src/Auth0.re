type options;
type client;

[@bs.module "@auth0/auth0-spa-js"]
external createClient: unit => Js.Promise.t(client) = "default";

type authState =
  | IsAuthenticated
  | NotLoggedIn;

type t = {authState};

module Context = {
  include ReactContext.Make({
    type context = t;

    let defaultValue = {authState: NotLoggedIn};
  });
};

module Provider = {
  [@react.component]
  let make = (~children) => {
    let (client, setClient) = React.useState(() => None);
    let (state, _) =
      React.useReducer((state, _action) => state, {authState: NotLoggedIn});

    React.useEffect0(() => {
      Js.Promise.(
        createClient()
        |> then_(client => {
             setClient(_ => Some(client));

             resolve(client);
           })
      )
      |> ignore;

      None;
    });

    <Context.Provider value=state> children </Context.Provider>;
  };
};
