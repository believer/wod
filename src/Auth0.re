type client;

[@bs.module "@auth0/auth0-spa-js"]
external createClient: Js.t('a) => Js.Promise.t(client) = "default";

[@bs.send]
external loginWithPopup: (client, unit) => Js.Promise.t('a) =
  "loginWithPopup";

[@bs.send]
external loginWithRedirect: (client, unit) => Js.Promise.t('a) =
  "loginWithRedirect";

[@bs.send]
external handleRedirectCallback: (client, unit) => Js.Promise.t('a) =
  "handleRedirectCallback";

[@bs.send]
external getUser: (client, unit) => Js.Promise.t(Js.t('a)) = "getUser";

[@bs.send]
external isAuthenticated: (client, unit) => Js.Promise.t(bool) =
  "isAuthenticated";
