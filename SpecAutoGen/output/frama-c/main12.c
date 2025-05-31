

/*@

ensures \result == p * n * r / 100;

*/

int simple(int p,int n,int r)

{
    int si;
    si = p*n*r/100;
    return si;
}
/*@

ensures \exists int retval_65;  retval_65 == 10000 * 3 * 10 / 100 ;
ensures  \result == 0;

*/

int main12()

{
    int s = simple(10000, 3,10);
    return 0;
}