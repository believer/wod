type system =
  | Metric
  | Imperial;

type t = {system};

let context = React.createContext({system: Metric});

module Provider = {
  let make = React.Context.provider(context);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};
