

/*@

ensures (b + c > a && a + c > b && a + b > c ) ==> ( \result == 1);

ensures (a + b <= c ) ==> ( \result == 0);

ensures (a + c <= b && a + b > c ) ==> ( \result == 0);

ensures (b + c <= a && a + c > b && a + b > c ) ==> ( \result == 0);

*/

int validts(int a, int b, int c) 
{
    int valid = 0;
    if ((a+b>c) && (a+c>b) && (b+c>a) && 1) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}