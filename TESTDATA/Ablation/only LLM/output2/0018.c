
int unknown1();

void foo(int flag) {
    unsigned int i, j, a, b;
    a = 0;
    b = 0;
    j = 1;
    if (flag) {
        i = 0;
    } else {
        i = 1;
    }

    /*@
      loop invariant a >= 0;
      loop invariant b == a * (j - i + 1) / 2;
      loop invariant i >= 0;
      loop invariant j >= 1;
      loop assigns a, b, i, j;
    */
    while (unknown1()) {
        a++;
        b += (j - i);
        i += 2;
        if (i % 2 == 0) {
            j += 2;
        } else {
            j++;
        }
    }
    if (flag) {
        /*@ assert a == b; */
    }
}
