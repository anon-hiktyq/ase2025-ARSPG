
// count_up_down_true-unreach-call_true-termination.c

/*@
requires n > 0;
ensures y == n;
*/
void foo(int n, int x, int y) {
    x = n;
    y = 0;


    while (x > 0) {
        x++;
        y--;
    }

    //@ assert y == n;
}
