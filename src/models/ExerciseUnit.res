type rec t = [
  | #Increasing(int)
  | #Meter(int)
  | #MeterWithFeet(int)
  | #Min(int)
  | #OneSide(int, int)
  | #Num(int)
  | #Cal(int)
  | #Cal2(int, int)
  | #Span(t, t)
  | #RepScheme
]
