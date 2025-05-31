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
          loop invariant l >= \at(l, Pre);
                */
                for (; k < n; k++){

    int i = l;
   
    
                /*@
           loop invariant i >= l;
           loop invariant l >= \at(l, Pre);
                */
                for (; k < n; i++){
      /*@ assert 1 <= i;*/
    }
                
    if(unknown1()) {
      l = l + 1;
    }
  }
                
}