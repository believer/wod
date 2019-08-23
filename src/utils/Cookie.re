module Config = {
  type t;

  [@bs.obj] external make: (~expires: int=?, ~path: string=?, unit) => t = "";
};

[@bs.module "js-cookie"]
external setStringConfig: (string, string, Config.t) => unit = "set";

[@bs.module "js-cookie"]
external getAsString: string => option(string) = "get";
