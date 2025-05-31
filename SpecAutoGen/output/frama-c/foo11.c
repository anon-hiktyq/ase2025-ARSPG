

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
/*@

ensures \exists int retval_58, retval_66;  -43 < 34 && retval_66 == 34 && 34 < 45  ==> retval_58 == 45;

*/

void foo11()

{
    int s = max(34,45);
    //@ assert s==45;
    int t = max(-43,34);
    //@ assert t==34;
}