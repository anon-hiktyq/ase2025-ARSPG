

/*@

ensures \result == p * n * r / 100;

*/

int simple(int p,int n,int r)

{
    int si;
    si = p*n*r/100;
    return si;
}