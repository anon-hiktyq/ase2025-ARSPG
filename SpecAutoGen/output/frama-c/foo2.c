

/*@

ensures \result == x + y;

*/

int add(int x, int y) 
{
    return x+y;
}
/*@

ensures \exists int retval_57, retval_64;  retval_64 == 997 + 997  ==> retval_57 == 1 + 43;

*/

void foo2() 
{
    int a = add(1, 43);
    //@ assert a == 44;
    int b = add(997, 997);
}