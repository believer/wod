let handleLinkClick = (to_, e) => {
  ReactEvent.Mouse.preventDefault(e)
  Route.go(to_)
}

module Link = {
  @react.component
  let make = (~className="", ~to_, ~children) => {
    let href = Route.toPath(to_)

    <a className href onClick={handleLinkClick(to_)}> children </a>
  }
}

module ExternalLink = {
  @react.component
  let make = (~href, ~children) => {
    <a className="text-blue-600 text-xs block mt-2" target="_blank" rel="noreferrer noopener" href>
      children
    </a>
  }
}

module NavLink = {
  let isActiveLink = (path, href) => {
    switch (path, href) {
    | (list{_, _}, "/")
    | (list{_, _}, "/all/all")
    | (list{}, "/all/all")
    | (list{}, "/") => true
    | (p, _) =>
      p |> List.exists(pathPart => href |> Js.String.split("/") |> Js.Array.includes(pathPart))
    }
  }

  @react.component
  let make = (~className, ~to_, ~children) => {
    let url = ReasonReactRouter.useUrl()
    let href = Route.toPath(to_)
    let isActive = isActiveLink(url.path, href)
    let className = Cn.fromList(list{className, "text-blue-500"->Cn.on(isActive)})

    <a ariaSelected=isActive className href onClick={handleLinkClick(to_)}> children </a>
  }
}
