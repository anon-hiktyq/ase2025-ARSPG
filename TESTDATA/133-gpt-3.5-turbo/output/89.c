
int unknown();

int main(int y,int v1,int v2,int v3) {

    int lock = 1;
    int x = y;

    
            
            /*@
          loop invariant (\at(y, Pre) != \at(y, Pre)) ==> (((x == \at(y, Pre))&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))) || (x == y));
          loop invariant (\at(y, Pre) != \at(y, Pre)) ==> (((x == \at(y, Pre))&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))) || (lock == 1));
          loop invariant (\at(y, Pre) != \at(y, Pre)) ==> (((x == \at(y, Pre))&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))) || (x == y));
          loop invariant (!(\at(y, Pre) != \at(y, Pre))) ==> ((x == \at(y, Pre))&&(lock == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre)));
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
