

/*@

ensures **a == **\old(a)&&*b == *\old(b)&&*r == *\old(r);
ensures \result == **\old(a) + *\old(b) + *\old(r) ;

*/

int add3(int **a, int *b, int *r) 
{
    return *(*a) + *b + *r;
}