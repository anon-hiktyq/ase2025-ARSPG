
// count_up_down_true-unreach-call_true-termination.c

/*@
requires n > 0;
*/
void foo(int n, int x, int y) {
	x = n;
	y = 0;
	
                /*@
          loop invariant x + y == \at(n, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant x <= 0 ==> y == n;
                */
                while (x > 0) {
		x++;
		y--;
	}
                
	//@ assert y == n;
}
