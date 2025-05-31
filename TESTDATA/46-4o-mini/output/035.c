
/*@
requires n > 0;
*/
void foo(int n) {
  int x = 0;
  
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : \at(n, Pre) > 0 && (x == 0) * (n == \at(n, Pre)) <<< */
    
            /*@
          loop invariant  (\at(n, Pre) > 0) ==> ((0<\at(n, Pre)) ==> (((x == 0)&&(n == \at(n, Pre))) || (x <= \at(n, Pre) && x >= 0))) ;
          loop invariant (\at(n, Pre) > 0) ==> ((!(0<\at(n, Pre))) ==> ((x == 0)&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
            */
            while(x < n) {
    x++;
  }
             
  /*@ assert (n > 0) ==> (x == n); */
 
}
