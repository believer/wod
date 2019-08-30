[@bs.module "localforage"]
external setItem: (string, string) => Js.Promise.t(string) = "setItem";

[@bs.module "localforage"]
external getItem: string => Js.Promise.t(string) = "getItem";

let set = (key, value) => setItem(key, value);
let get = key => getItem(key);
