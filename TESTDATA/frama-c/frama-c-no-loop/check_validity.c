

/*@

ensures (c <= 0 && b > 0 && a > 0 && a + b + c == 180 ) ==> ( \result == 0);

ensures (b <= 0 && a > 0 && a + b + c == 180 ) ==> ( \result == 0);

ensures (a <= 0 && a + b + c == 180 ) ==> ( \result == 0);

ensures (a + b + c != 180 ) ==> ( \result == 0);

ensures (c > 0 && b > 0 && a > 0 && a + b + c == 180 ) ==> ( \result == 1);

*/

int triangle(int a, int b, int c) 
{
    if ((a+b+c == 180) && a > 0 && b > 0 && c > 0) {
        return 1;
    } else {
        return 0;
    }
}
/*@

ensures \exists int retval_61, retval_71;  90 + 145 + 145 != 180 && retval_71 == 0 && 45 > 0 && 45 > 0 && 90 > 0 && 90 + 45 + 45 == 180  ==> retval_61 == 1;

*/

void check_validity() 
{
    int res = triangle(90, 45, 45);
    //@ assert res == 1;
    res = triangle(90, 145, 145);
    //@ assert res == 0;
}