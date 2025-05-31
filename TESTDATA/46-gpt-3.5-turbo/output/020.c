
   int unknown();

   /*@
   requires (x + y) == k;
   requires n > 0;
   */
   void foo(int x, int y, int k, int j, int i, int n) {

     int m = 0;
     j = 0;

     /*@
       loop invariant  (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (((m == 0)&&(n == \at(n, Pre))&&(i == \at(i, Pre))&&(j == 0)&&(k == \at(k, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || (j <= n)));
       loop invariant  (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (((m == 0)&&(n == \at(n, Pre))&&(i == \at(i, Pre))&&(j == 0)&&(k == \at(k, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || (j <= n)));  // Changed here
       loop invariant  (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (((m == j)&&(n == \at(n, Pre))&&(i == \at(i, Pre))&&(0 <= j)&&(j <= n)&&(k == \at(k, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || (j >= 0)));
       loop invariant  (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> ((!(0 < \at(n, Pre))) ==> ((m == 0)&&(n == \at(n, Pre))&&(i == \at(i, Pre))&&(j == 0)&&(k == \at(k, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))));
       loop invariant (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> (n == \at(n, Pre));
       loop invariant (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> (i == \at(i, Pre));
       loop invariant (\at(x, Pre) + \at(y, Pre) == \at(k, Pre) && \at(n, Pre) > 0) ==> (k == \at(k, Pre));
     */
     while (j < n) {
       if (j == i) {
         x++;
         y--;
       } else {
         y++;
         x--;
       }
       if (unknown()){
         m = j;
       }
       j++;
     }

     /*@ assert (x + y) == k; */

     /*@ assert(n > 0) ==> (0 <= m && m < n);*/
   }
