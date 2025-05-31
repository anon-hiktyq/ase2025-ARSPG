
void foo(int x, int y,int z1,int z2,int z3) {

    int i = x;
    int j = y;

    /*@       loop invariant (x == 0) ==> (y == j) ; 
    */
    while (x != 0) {
        x = x - 1;
        y = y - 1;
    }

    /*@ assert (i == j) ==> (y == 0); */
}
