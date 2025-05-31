
void main6() {
    int i = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  0 <= i <= 30 ;
    */
    while (i < 30) {
        ++i;
    }

    /*@ assert i == 30; */
}
