

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