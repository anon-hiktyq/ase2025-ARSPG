

/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i,k;

  k = 1;
  for (k=1; k<n; k++){
  	i = l;
    for (i=l; i<n; i++) {
    }

    }
  
    /*@ assert \forall integer i; (l <= i < n) ==> (1 <= i); */
  

}
