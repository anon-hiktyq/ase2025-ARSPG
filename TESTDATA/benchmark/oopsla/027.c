
/*@
requires l > 0;
*/
void foo(int l,int n) {
  int i, k;
 

  k = 1;
  for (k = 1; k < n; k++) {
    i = l;
    for (i = l; i < n; i++) {

    }

    /*@ assert \forall i; (l <= i < n) ==> (1 <= k); */
  }

}