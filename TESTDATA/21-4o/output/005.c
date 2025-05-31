
// count_up_down_true-unreach-call_true-termination.c

/*@
requires n > 0;
*/
void foo(int n, int x, int y) {
	x = n;
	y = 0;
	
                
                /*@
          loop invariant  (\at(n, Pre) > 0) ==> ((\at(n, Pre) > 0) ==> (((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre))) || ((x + y == \at(n, Pre)) && ((x >= 0) && (y <= 0))))) ;
          loop invariant  (\at(n, Pre) > 0) ==> ((\at(n, Pre) > 0) ==> (((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre))) || ((x + y == \at(n, Pre)) && ((x >= 0) && (y <= 0))))) ;
          loop invariant (\at(n, Pre) > 0) ==> ((!(\at(n, Pre) > 0)) ==> ((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
                */
                while (x > 0) {
		x++;
		y--;
	}
                

	//@ assert y == n;

}
