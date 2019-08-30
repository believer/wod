[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => <Workouts />
  | _ => <FourOFour />
  };
};
