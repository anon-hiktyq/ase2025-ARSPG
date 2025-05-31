

/*@

ensures (\old(*a) < \old(*b) ) ==> (*a == \old(*a)&&*b == \old(*b));
ensures (\old(*a) < \old(*b) ) ==> ( \result == \old(*b) );

ensures (\old(*a) >= \old(*b) ) ==> (*a == \old(*a)&&*b == \old(*b));
ensures (\old(*a) >= \old(*b) ) ==> ( \result == \old(*a) );

*/

int max_ptr(int *a, int *b)
{
    return (*a < *b) ? *b : *a ;
}