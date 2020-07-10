type t = string

@bs.module("cuid") external make: unit => t = "default"

let toString = id => id
