
/*@
ensures \result >= 0;
*/
int unknown();

/*@
requires n > 0;
*/
void foo(int n, int flag) {
  int k = 1;
  if (flag) {
    k = unknown();
  }
  int i = 0, j = 0;
  
  /*@
    loop invariant  (\at(flag, Pre) == 0 && \at(n, Pre) > 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(k == 1)&&(flag == \at(flag, Pre))&&(n == \at(n, Pre))) || (i >= 0 && i <= n + 1))) ;
    loop invariant  (\at(flag, Pre) == 0 && \at(n, Pre) > 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(k == 1)&&(flag == \at(flag, Pre))&&(n == \at(n, Pre))) || (j == i * (i + 1) / 2))) ;
    loop invariant  (\at(flag, Pre) == 0 && \at(n, Pre) > 0) ==> (flag == \at(flag, Pre));
    loop invariant  (\at(flag, Pre) == 0 && \at(n, Pre) > 0) ==> (n == \at(n, Pre));
    loop invariant  (k >= 0 && \at(flag, Pre) != 0 && \at(n, Pre) > 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(flag == \at(flag, Pre))&&(n == \at(n, Pre))) || (i >= 0 && i <= n + 1))) ;
    loop invariant  (k >= 0 && \at(flag, Pre) != 0 && \at(n, Pre) > 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(flag == \at(flag, Pre))&&(n == \at(n, Pre))) || (j == i * (i + 1) / 2))) ;
    loop invariant  (k >= 0 && \at(flag, Pre) != 0 && \at(n, Pre) > 0) ==> (flag == \at(flag, Pre));
    loop invariant  (k >= 0 && \at(flag, Pre) != 0 && \at(n, Pre) > 0) ==> (n == \at(n, Pre));
  */
  while (i <= n) {
    i++;
    j += i;
  }
      
  int z = k + i + j;
  /*@ assert z > 2 * n; */
}
