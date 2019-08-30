let handleLinkClick = e => {
  ReactEvent.Mouse.preventDefault(e);
  let anchor = ReactEvent.Mouse.currentTarget(e);
  ReasonReactRouter.push(anchor##href);
};

module Link = {
  [@react.component]
  let make = (~className="", ~href, ~children) => {
    <a className href onClick=handleLinkClick> children </a>;
  };
};
