
int unknown();

void foo()
{
	int i = 1;
	int j = 0;
	int z = i - j;
	int x = 0;
	int y = 0;
	int w = 0;


	
            
            /*@
          loop invariant  ((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (z % 2 == 1) ;
          loop invariant  ((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (x == y) ;
          loop invariant  ((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (y >= 0) ;
          loop invariant  ((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (w == 2*y) ;
          loop invariant j == 0;
          loop invariant i == 1;
            */
            while(unknown()) 
	{
		z += x + y + w;
		y++;
		if (z % 2 == 1) 
		  x++;
		w += 2; 
	}
            

	/*@ assert x ==y ;*/
}
