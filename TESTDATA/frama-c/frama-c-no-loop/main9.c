

/*@

ensures \result == x - y;

*/

int diff (int x, int y) 
{
    return x-y;
}
/*@

ensures \exists int retval_57;  retval_57 == 10 - 5;

*/

void main9() 
{
    int t = diff(10, 5);
    //@ assert t == 5;
}