
int unknown();

void foo()
{
 int x = 1;
 int y = 1;

 while(unknown()) {
   int t1 = x;
   int t2 = y;
   x = t1 + t2;
   y = t1 + t2;
 }
 /*@ assert y >= 1 ;*/
}

