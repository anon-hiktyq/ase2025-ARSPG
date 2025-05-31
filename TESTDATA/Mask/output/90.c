
int unknown();

int main(int x,int v1,int v2,int v3) {

    int lock = 1;
    int y = x + 1;

    
                
                /*@
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1)&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(x == \at(x, Pre))) || ((y >= \at(x, Pre) + 1)&&(x <= y)));
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1)&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(x == \at(x, Pre))) || ((lock == 0)||(lock == 1)));
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> ((y >= \at(x, Pre) + 1)&&(x <= y));
          loop invariant (!(\at(x, Pre) != \at(x, Pre) + 1)) ==> ((y == \at(x, Pre) + 1)&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(x == \at(x, Pre)));
          loop invariant v3 == \at(v3, Pre);
          loop invariant v2 == \at(v2, Pre);
          loop invariant v1 == \at(v1, Pre);
                */
                while (x != y) {
        if (unknown()) {
          
          lock  = 1;
          x  = y;
          
        } else {
          
          lock  = 0;
          x  = y;
          y  = y + 1;
          
        }
 
    }
                
    /*@ assert lock == 1;*/
  }
