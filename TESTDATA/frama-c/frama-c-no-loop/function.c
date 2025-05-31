

/*@

ensures \result == \old(x) - 5 + (\old(y) + 10);

*/

int function(int x, int y) 
{
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    //@ assert res == \at(x,Pre) + \at(y,Pre) + 5;
    return res ;
}