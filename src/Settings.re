type system =
  | Metric
  | Imperial;

type t = {system};

module Context = {
  include ReactContext.Make({
    type context = t;

    let defaultValue = {system: Metric};
  });
};

let use = () => React.useContext(Context.t);
