
/*@
requires n > 0;
*/
void foo(int n) {
  int x= 0;
  
  while(x<n) {
    x++;
  } 
  /*@ assert (n > 0) ==> (x == n); */
 
}
