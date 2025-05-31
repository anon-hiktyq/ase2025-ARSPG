
int unknown();

void foo(int i, int j) {
  
  int x = i;
  int y = j;
 
            /*@          loop invariant (\at(i, Pre) != 0) ==> (((y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || (y == \at(j, Pre) - (\at(i, Pre) - x)));
          loop invariant (!(\at(i, Pre) != 0)) ==> ((y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre)));
          loop invariant j == \at(j, Pre);
          loop invariant i == \at(i, Pre);
            */
            while(x != 0) {
	  x--;
	  y--;
  }
            
  /*@ assert (i == j) ==> (y == 0);*/
}
