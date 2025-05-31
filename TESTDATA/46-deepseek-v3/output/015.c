
/*@
requires n > 0;
requires k > n;
*/
void foo(int n, int k) {

  int j = 0;

  
            
            /*@
          loop invariant  (\at(n, Pre) > 0 && \at(k, Pre) > \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((j == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))) || (k == \at(k, Pre) - j))) ;
          loop invariant  (\at(n, Pre) > 0 && \at(k, Pre) > \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((j == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))) || (j <= \at(n, Pre)))) ;
          loop invariant (\at(n, Pre) > 0 && \at(k, Pre) > \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((j == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) > 0 && \at(k, Pre) > \at(n, Pre)) ==> (n == \at(n, Pre));
            */
            while( j < n ) {
    j++;
    k--;
  }
             
  /*@ assert k>=0; */
}
