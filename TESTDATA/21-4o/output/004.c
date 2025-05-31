
void foo() {
    int i, j;
    i = 1;
    j = 10;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant  ((j == 10)&&(i == 1)) || (i == 2 * (10 - j) + 1);
      loop invariant  ((j == 10)&&(i == 1)) || (j >= 6);
    */
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }

    /*@ assert j == 6; */
    return;
}
