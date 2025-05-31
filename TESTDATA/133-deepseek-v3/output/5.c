
void foo(int size,int y,int z)
{
    int x = 0;
    
   
    
            
            /*@
          loop invariant (0 < \at(size, Pre)) ==> (((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))&&(size == \at(size, Pre))) || (y == \min(\at(y, Pre), \at(z, Pre))));
          loop invariant (0 < \at(size, Pre)) ==> (((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))&&(size == \at(size, Pre))) || (0 <= x <= \at(size, Pre)));
          loop invariant (!(0 < \at(size, Pre))) ==> ((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))&&(size == \at(size, Pre)));
          loop invariant z == \at(z, Pre);
          loop invariant size == \at(size, Pre);
            */
            while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }
            

   /*@ assert (size > 0) ==> (z >= y);  */
}
