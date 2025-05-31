
/*@
requires 0 <= i && i < 1000000;
requires j >= 0;
*/
void foo(int i, int j) {

    int x = i;
    int y = j;
    int z = 0;
  
    while (x != 0) {
        x--;
        y -= 2;
        z++;
    }

    if (i == j) {
        /*@ assert y == -z; */
    }
    
}
