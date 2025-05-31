
int unknown();

int main(int x) {

    int lock = 1;
    int y = x + 1;

    
            
            /*@
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1)&&(lock == 1)&&(x == \at(x, Pre))) || (y >= x && (lock == 0 || lock == 1)));
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1)&&(lock == 1)&&(x == \at(x, Pre))) || (lock == 0 || lock == 1));
          loop invariant (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1)&&(lock == 1)&&(x == \at(x, Pre))) || (y >= \at(x, Pre) + 1));
          loop invariant (!(\at(x, Pre) != \at(x, Pre) + 1)) ==> ((y == \at(x, Pre) + 1)&&(lock == 1)&&(x == \at(x, Pre)));
          loop invariant x != y ==> (y > x);
          loop invariant x == y ==> lock == 1;
            */
            while (x != y) {
        if ( unknown() ) {
          
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
