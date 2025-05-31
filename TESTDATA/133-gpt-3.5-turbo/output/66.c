
    void foo(int y) {
        int x = 1;

        /*@          loop invariant  ((x == 1)&&(y == \at(y, Pre))) || (y >= 0 && y <= 99) ;
        */
        while (x <= 100) {
            y = 100 - x;
            x = x + 1;
        }

        /*@ assert (y < 100); */
    }
    