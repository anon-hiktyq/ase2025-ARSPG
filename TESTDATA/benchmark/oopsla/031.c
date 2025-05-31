
int unknown();

/*@ requires m + 1 < n; */
void foo(int i,int j,int k,int n,int m) {

  i = 0;
  for (i = 0; i < n; i += 4) {
    j = i;
    for (j = i; j < m;) {
        
      if (unknown()) {
        /*@ assert j >= 0;*/
        j++;
        k = 0;
        while (k < j) {
          k++;
        }
      } else {
        /*@ assert n + j + 5 > i;*/
        j += 2;
      }
    }
  }
}