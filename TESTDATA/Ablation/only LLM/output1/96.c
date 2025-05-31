
void foo(int x) {
    int i = 0;
    int j = 0;
    int y = 1;
    
    /*@ 
      loop invariant 0 <= i <= x + 1;
      loop invariant j == i * y;
      loop assigns i, j;
      loop variant x - i;
    */
    while (i <= x) {
        i = i + 1;
        j = j + y;
    }

    /*@ assert (i != j) ==> (y != 1); */
}
