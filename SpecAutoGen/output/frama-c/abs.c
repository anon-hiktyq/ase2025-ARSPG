

/*@

ensures (val >= 0 ) ==> ( \result == val);

ensures (val < 0 ) ==> ( \result == -val);

*/

int abs(int val) 
{
    if(val < 0) return -val;
    return val;
}