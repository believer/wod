type rec t = [
  | #Increasing(int)
  | #Max
  | #Meter(int)
  | #MeterWithFeet(int)
  | #Min(int)
  | #OneSide(int, int)
  | #Num(int)
  | #Num2(int, int)
  | #Cal(int)
  | #Cal2(int, int)
  | #Span(t, t)
  | #RepScheme
]
