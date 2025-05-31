
/*@
requires y <= 1000000;
*/
void foo(int x, int y) {

	if (y > 0) {
		
		while (x < 100) {
			x = x + y;
		}
	}

	//@ assert y <= 0 || (y > 0 && x >= 100);
}
