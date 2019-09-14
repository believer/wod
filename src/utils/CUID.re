module Generate: {
  type t;
  let toString: t => string;
  let make: unit => t;
} = {
  type t = string;

  [@bs.module "cuid"] external make: unit => t = "default";

  let toString = id => id;
};
