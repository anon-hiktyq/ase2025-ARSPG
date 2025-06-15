

/*@

ensures *a == *\old(a)&&*b == *\old(b)&&*r == *\old(r);
ensures \result == *\old(a) + *\old(a) + *\old(b);

*/

int add13(int *a, int *b, int *r) 
{
    return *a + *b + *r;
}