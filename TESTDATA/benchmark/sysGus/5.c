void foo(int size,int y,int z)
{
    int x = 0;
    
   
    while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

   /*@ assert (size > 0) ==> (z >= y);  */
}