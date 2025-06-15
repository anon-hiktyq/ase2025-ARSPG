

/*@

ensures *p == *\old(p)&&*q == *\old(q);
ensures \result == *\old(p) + *\old(q);

*/

int add14(int *p, int *q) 
{
    return *p + *q;
}