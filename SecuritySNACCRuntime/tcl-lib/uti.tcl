# file: uti.tcl

#\[sep]-----------------------------------------------------------------------------------------------------------------------------
proc max {a0 args} \
{
  set max $a0
  foreach a $args \
  {
    if {$a > $max} \
    {
      set max $a
    }
  }
  return $max
}
