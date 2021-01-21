module Config = {
  type t

  @obj external make: (~expires: int=?, ~path: string=?, unit) => t = ""
}

@module("js-cookie")
external setStringConfig: (string, string, Config.t) => unit = "set"

@module("js-cookie")
external getAsString: string => option<string> = "get"
