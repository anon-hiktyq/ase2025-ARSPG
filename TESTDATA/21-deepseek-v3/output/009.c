
/*@
requires i >= 0 && j >= 0;
*/
void foo(int i, int j) {
    int x = i;
    int y = j;
    
    /*@
      loop invariant (\at(i, Pre) >= 0 && \at(j, Pre) >= 0) ==> ((\at(i, Pre) != 0) ==> (((y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || (y - x == \at(j, Pre) - \at(i, Pre)))) ;
      loop invariant (\at(i, Pre) >= 0 && \at(j, Pre) >= 0) ==> ((\at(i, Pre) != 0) ==> (((y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))) || (y - x == \at(j, Pre) - \at(i, Pre)))) ;
      loop invariant (\at(i, Pre) >= 0 && \at(j, Pre) >= 0) ==> ((!(\at(i, Pre) != 0)) ==> ((y == \at(j, Pre))&&(x == \at(i, Pre))&&(j == \at(j, Pre))&&(i == \at(i, Pre))));
      loop invariant (\at(i, Pre) >= 0 && \at(j, Pre) >= 0) ==> (j == \at(j, Pre));
      loop invariant (\at(i, Pre) >= 0 && \at(j, Pre) >= 0) ==> (i == \at(i, Pre));
    */
    while (x != 0) {
        x--;
        y--;
    }

    if (i == j) {
        /*@ assert y == 0;*/
    }
}
