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

module NavLink = {
  let isActiveLink = (path, href) => {
    switch (path, href) {
    | ([_, _], "/")
    | ([_, _], "/all/all")
    | ([], "/all/all")
    | ([], "/") => true
    | (p, _) =>
      p
      |> List.exists(pathPart =>
           href |> Js.String.split("/") |> Js.Array.includes(pathPart)
         )
    };
  };

  [@react.component]
  let make = (~className, ~to_, ~children) => {
    let url = ReasonReactRouter.useUrl();
    let href = Route.toPath(to_);
    let isActive = isActiveLink(url.path, href);
    let className =
      Cn.make([className, "text-blue-500"->Cn.ifTrue(isActive)]);

    <a
      ariaSelected=isActive
      className
      href
      onClick={e => {
        ReactEvent.Mouse.preventDefault(e);
        Route.go(to_);
      }}>
      children
    </a>;
  };
};
