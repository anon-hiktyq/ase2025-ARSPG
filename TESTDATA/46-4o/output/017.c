
void foo(int n)
{
    int k = 1;
    int i = 1;
    int j = 0;

    /*@ 
        loop invariant (!(1 < \at(n, Pre))) ==> ((j == 0) && (i == 1) && (k == 1) && (n == \at(n, Pre)));
    */
    while (i < n) {
        j = 0;

        /*@ 
        */
        while (j < i) {
            k += (i - j);
            j++;
        }

        i++;
    }

    /*@ assert k >= n; */
}
