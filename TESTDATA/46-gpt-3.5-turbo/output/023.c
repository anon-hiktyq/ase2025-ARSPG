
/*@
requires n >= 0;
*/
void foo(int n) {
  int i, sum = 0;
  
            /*@
          loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (((sum == 0)&&(i == 0)&&(n == \at(n, Pre))) || (i <= \at(n, Pre) && sum == (i * (i - 1) / 2)))) ;
          loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (((sum == 0)&&(i == 0)&&(n == \at(n, Pre))) || (sum == (i * (i - 1) / 2))));
          loop invariant (\at(n, Pre) >= 0) ==> ((!(0 < \at(n, Pre))) ==> ((sum == 0)&&(i == 0)&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) >= 0) ==> (n == \at(n, Pre));
            */
            for (i = 0; i < n; ++i){
    sum = sum + i;
  }
            

  /*@ assert sum >= 0; */
}
