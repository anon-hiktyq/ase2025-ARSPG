
/*@
requires i >= 0 && j >= 0;
*/
void foo(int i, int j) {

    int x = i;
    int y = j;
    

    while (x != 0) {
        x--;
        y--;
    }

    if (i == j) {
        /*@ assert y == 0;*/
    }
    

}
