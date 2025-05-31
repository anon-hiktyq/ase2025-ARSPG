
/*@
requires 0 <= i && i < 1000000;
requires j >= 0;
*/
void foo(int i, int j) {


    int x = i;
    int y = j;
    int z = 0;
    

    
                
                /*@
          loop invariant  (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> ((\at(i, Pre) != 0) ==> (((z == 0)&&(y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || ((0 <= x && x < \at(i, Pre))))) ;
          loop invariant  (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> ((\at(i, Pre) != 0) ==> (((z == 0)&&(y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || ((y == \at(j, Pre) - 2*(\at(i, Pre) - x))))) ;
          loop invariant  (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> ((\at(i, Pre) != 0) ==> (((z == 0)&&(y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || ((z == \at(i, Pre) - x)))) ;
          loop invariant (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> ((!(\at(i, Pre) != 0)) ==> ((z == 0)&&(y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))));
          loop invariant (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> (j == \at(j, Pre));
          loop invariant (0 <= \at(i, Pre) && \at(i, Pre) < 1000000 && \at(j, Pre) >= 0) ==> (i == \at(i, Pre));
                */
                while (x != 0) {
    	x--;
    	y -= 2;
    	z++;
    }
                

    if (i == j) {
    	/*@ assert y == -z;*/
    }
    
}
