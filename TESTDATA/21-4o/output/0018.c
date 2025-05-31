
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
                
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant (\at(flag, Pre) == 0) ==> (flag == \at(flag, Pre));
      loop invariant (\at(flag, Pre) != 0) ==> (flag == \at(flag, Pre));
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
        /*@ assert a == b;*/
    }
}
