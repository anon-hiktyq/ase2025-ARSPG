int unknown();


void foo(int i, int j) {
  
  int x = i;
  int y = j;
 
 
  while(x != 0) {
	  x--;
	  y--;
  }

  /*@ assert (i == j) ==> (y == 0);*/
}
