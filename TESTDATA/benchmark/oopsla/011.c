


void foo()
{
  int j = 0;
  int i = 0;
  int x = 100;
   
 
  for (i = 0; i < x ; i++){
    j = j + 2;
  }

  /*@ assert j == 2*x; */
}
