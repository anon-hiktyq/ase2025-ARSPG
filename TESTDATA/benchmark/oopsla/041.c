
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
    k = unknown1();
  }
  int i = 0, j = 0;
  while (i <= n) {
    i++;
    j += i;
  }
  int z = k + i + j;
  /*@ assert z > 2 * n; */
}