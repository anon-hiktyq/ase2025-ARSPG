

/*@

ensures \result == base * height / 2;

*/

int area(int base, int height)
{
    int res = (base * height) / 2;
    return res;
}
/*@

ensures \exists int retval_61;  retval_61 == 4 * 5 / 2 ==> \result == 0;

*/

int main3() 
{
    int a = area(4, 5);
    //@ assert a == 10;
    return 0;
}