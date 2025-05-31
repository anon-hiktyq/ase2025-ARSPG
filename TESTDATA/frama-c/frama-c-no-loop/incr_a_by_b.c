

/*@

ensures *a == \old(*a) + \old(*b)&&*b == \old(*b);
ensures \result == \old(*a) + \old(*b) ;

*/

int incr_a_by_b(int* a, int * b)
{
    *a += *b;
    return *a;
}