

/*@

ensures (x < y ) ==> ( \result == y);

ensures (x >= y ) ==> ( \result == x);

*/

int max ( int x, int y ) 
{
    if ( x >=y ) 
        return x ;
    return y ;
}