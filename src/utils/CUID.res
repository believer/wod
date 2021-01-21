type t = string

@module("cuid") external make: unit => t = "default"

let toString = id => id
