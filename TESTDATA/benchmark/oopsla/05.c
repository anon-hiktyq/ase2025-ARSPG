
int unknown();

void foo(int flag)
{

	int x = 0;
	int y = 0;
	int j = 0;
	int i = 0;

   
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