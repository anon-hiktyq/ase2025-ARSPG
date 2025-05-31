
/*@
requires n >= 0;
*/
void foo(int n) {
  int i, sum = 0;
 
  for (i = 0; i < n; ++i){
    sum = sum + i;
  }

  /*@ assert sum >= 0; */
}