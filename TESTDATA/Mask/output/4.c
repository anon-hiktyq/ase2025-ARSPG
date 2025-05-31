
void foo(int y, int z)
{
    int x = 0;   

                
                /*@
          loop invariant  0 <= x <= 500 ;
          loop invariant z == \at(z, Pre);
                */
                while(x < 500) {
   x += 1;
   if( z <= y) {
      y = z;
   }
}
                


   
    /*@ assert z >= y; */
}
