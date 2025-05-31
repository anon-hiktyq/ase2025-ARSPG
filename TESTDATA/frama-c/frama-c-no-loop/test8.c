

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
/*@

ensures \exists int retval_67;  3 + 4 > 2 && 2 + 4 > 3 && 2 + 3 > 4  ==> retval_67 == 1;

*/

void test8() 
{
    int valid = validts(2,3,4);
    //@ assert valid == 1;
}