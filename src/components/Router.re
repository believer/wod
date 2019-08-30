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

module ExternalLink = {
  [@react.component]
  let make = (~href, ~children) => {
    <a
      className="text-blue-600 text-xs block mt-2"
      target="_blank"
      rel="noreferrer noopener"
      href>
      children
    </a>;
  };
};
