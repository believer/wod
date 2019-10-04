open Js.Promise;

[@bs.val] external query: string = "window.location.search";

module User = {
  type t = {email: string};

  let make = user => {email: user##email};
};

type authState =
  | Authenticating
  | Authenticated(User.t)
  | NotLoggedIn;

type action =
  | Login
  | GetUser
  | UpdateAuthState(authState);

type t = {
  authState,
  login: unit => unit,
};

module Context = {
  include ReactContext.Make({
    type context = t;

    let defaultValue = {authState: NotLoggedIn, login: _ => ()};
  });
};

let useAuth = () => React.useContext(Context.t);

module Provider = {
  [@react.component]
  let make = (~children) => {
    let (client, setClient) = React.useState(() => None);
    let (state, dispatch) =
      ReactUpdate.useReducer(NotLoggedIn, (action, _state) =>
        switch (action) {
        | UpdateAuthState(authState) => Update(authState)
        | GetUser =>
          UpdateWithSideEffects(
            Authenticating,
            ({send}) => {
              switch (client) {
              | Some(client) =>
                client->Auth0.getUser()
                |> then_(user => {
                     send(UpdateAuthState(Authenticated(User.make(user))));
                     resolve();
                   })
                |> ignore
              | None => ()
              };

              None;
            },
          )
        | Login =>
          UpdateWithSideEffects(
            Authenticating,
            ({send}) => {
              switch (client) {
              | Some(client) =>
                client->Auth0.loginWithRedirect()
                |> then_(_ => {
                     send(GetUser);
                     resolve();
                   })
                |> ignore
              | None => ()
              };

              None;
            },
          )
        }
      );

    React.useEffect0(() => {
      Auth0.createClient({
        "domain": Config.Auth0.domain,
        "client_id": Config.Auth0.client,
        "redirect_uri": Config.Auth0.redirect,
      })
      |> then_(client => {
           setClient(_ => Some(client));

           if (query |> Js.String.includes("code=")) {
             client->Auth0.handleRedirectCallback()
             |> then_(_ => {
                  ReasonReactRouter.push("/");
                  resolve();
                })
             |> ignore;
           };

           client->Auth0.isAuthenticated()
           |> then_(isAuthenticated => {
                if (isAuthenticated) {
                  dispatch(GetUser);
                };

                resolve();
              })
           |> ignore;

           resolve(client);
         })
      |> ignore;

      None;
    });

    <Context.Provider value={authState: state, login: _ => dispatch(Login)}>
      children
    </Context.Provider>;
  };
};
