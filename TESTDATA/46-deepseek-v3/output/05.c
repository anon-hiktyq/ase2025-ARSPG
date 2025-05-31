
int unknown();

void foo(int flag)
{
	int x = 0;
	int y = 0;
	int j = 0;
	int i = 0;

            /*@
          loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (x == y) ;
          loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (y == x) ;
          loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j == i + (flag ? x : 0)) ;
          loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (i == x * (x + 1) / 2) ;
          loop invariant flag == \at(flag, Pre);
          loop invariant j >= i;
            */
            while(unknown())
	{
	  x++;
	  y++;
	  i += x;
	  j += y;
	  if (flag){
	  	j+=1;
      }
	}
             
	/*@ assert j>=i; */
}
