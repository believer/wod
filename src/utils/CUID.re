module Generate: {
  type t;
  let toString: t => string;
  let make: unit => t;
} = {
  type t = string;

  [@bs.module] external make: unit => t = "cuid";

  let toString = id => id;
};
