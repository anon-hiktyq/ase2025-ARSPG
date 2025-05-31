
#include <limits.h>

int unknown1();

/*@
requires l > 0;
requires l < INT_MAX;
requires n < INT_MAX;
*/
void foo(int n, int l) {
  int k;

  
  for (k = 1; k < n; k++){

    int i= 1;
    
    for (i = l; i < n; i++){
      /*@ assert 1 <= i;*/
    }
    if(unknown1()) {
      l = l + 1;
    }
  }
}
