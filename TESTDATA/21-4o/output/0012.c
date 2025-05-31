
#include <limits.h>

int unknown1();

/*@
requires l > 0;
requires l < INT_MAX;
requires n < INT_MAX;
*/
void foo(int n, int l) {
  int k = 1;

  
                
                /*@
          loop invariant k >= 1;
          loop invariant l > 0;
                */
                for (; k < n; k++){

    int i = l;
   
    
                
                /*@
           loop invariant 1 <= k <= n;
           loop invariant i >= l;
           loop invariant l > 0;
                */
                for (; k < n; i++){
      /*@ assert i >= l;*/
    }
                
    if(unknown1()) {
      l = l + 1;
    }
  }
                
}
