
void foo()
{
	int i = 1;
	int j = 0;
	int z = i - j;
	int x = 0;
	int y = 0;
	int w = 0;

	/* >>> LOOP INVARIANT TO FILL <<< */
        
	/*@
          loop invariant i == 1;
          loop invariant j == 0;
          loop invariant x >= 0;
          loop invariant y >= 0;
          loop invariant w >= 0;
	*/
	while(unknown()) 
	{
		z += x + y + w;
		y++;
		if (z % 2 == 1) 
		  x++;
		w += 2; 
	}

	/*@ assert x == y ;*/
}
