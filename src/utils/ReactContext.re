module type Config = {
  type context;
  let defaultValue: context;
};

module Make = (Config: Config) => {
  let t = React.createContext(Config.defaultValue);

  module Provider = {
    let make = t->React.Context.provider;

    [@bs.obj]
    external makeProps:
      (
        ~value: Config.context,
        ~children: React.element,
        ~key: string=?,
        unit
      ) =>
      {
        .
        "value": Config.context,
        "children": React.element,
      } =
      "";
  };
};
