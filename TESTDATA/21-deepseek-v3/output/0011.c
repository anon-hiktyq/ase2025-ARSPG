
/*@
  loop invariant (0 >= \at(n1, Pre) && 0 >= \at(n0, Pre) && 
                 INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && 
                 INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> 
                 (k > 0 || j1 == \at(n0, Pre) + \at(n1, Pre));
*/
