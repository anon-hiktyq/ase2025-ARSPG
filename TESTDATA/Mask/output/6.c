
void foo(int v1, int v2 ,int v3,int size, int y, int z)
{
    
    int x = 0;

    
                
                /*@
          loop invariant (0 < \at(size, Pre)) ==> (((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))&&(size == \at(size, Pre))&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))) || ((0 <= x <= size) && (z == \at(z, Pre)) && (size == \at(size, Pre)) && (v3 == \at(v3, Pre)) && (v2 == \at(v2, Pre)) && (v1 == \at(v1, Pre)) && ((z <= y) ==> (y == z)) && ((z > y) ==> (y == \at(y, Pre)))));
          loop invariant (0 < \at(size, Pre)) ==> ((0 <= x <= size));
          loop invariant (!(0 < \at(size, Pre))) ==> ((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))&&(size == \at(size, Pre))&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre)));
          loop invariant z == \at(z, Pre);
          loop invariant size == \at(size, Pre);
          loop invariant v3 == \at(v3, Pre);
          loop invariant v2 == \at(v2, Pre);
          loop invariant v1 == \at(v1, Pre);
                */
                while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }
                

    /*@ assert (size > 0) ==> (z >= y);  */

}
