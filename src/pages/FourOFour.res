@react.component
let make = () => {
  <div className="flex flex-col items-center justify-center h-screen">
    <h1 className="text-6xl font-semibold">
      {React.string("That's a no rep")}
    </h1>
    <p className="text-xl mt-2">
      {React.string("This page does not exist. ")}
    </p>
    <p className="text-xl">
      <Router.Link to_={Route.Home((None, None))} className="text-blue-500">
        {React.string("Back to start page")}
      </Router.Link>
    </p>
  </div>
}
