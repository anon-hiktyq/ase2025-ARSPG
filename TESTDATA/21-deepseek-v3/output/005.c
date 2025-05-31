
// Probable correct version if loop was decreasing x
/*@
requires n > 0;
*/
void foo(int n, int x, int y) {
	x = n;
	y = 0;
	
                /*@
          loop invariant x + y == n;
          loop invariant n == \at(n, Pre);
          loop invariant x >= 0;
                */
                while (x > 0) {
		x--;  // decreasing instead of increasing
		y++;  // increasing instead of decreasing
	}
                
	//@ assert y == n;
}
