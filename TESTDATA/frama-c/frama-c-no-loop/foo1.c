

/*@

ensures (val >= 0 ) ==> ( \result == val);

ensures (val < 0 ) ==> ( \result == -val);

*/

int abs(int val) 
{
    if(val < 0) return -val;
    return val;
}
/*@

ensures \exists int retval_56, retval_64, retval_71, retval_81;  -997 < 0 && retval_81 == --997 && a >= 0 && retval_71 == a && 42 >= 0 && retval_64 == 42 && -42 < 0  ==> retval_56 == --42;

ensures \exists int retval_56, retval_64, retval_70, retval_77;  -997 < 0 && retval_77 == --997 && a < 0 && retval_70 == -a && 42 >= 0 && retval_64 == 42 && -42 < 0  ==> retval_56 == --42;

*/

void foo1(int a) 
{
    int b = abs(-42);
    //@ assert b == 42;
    int c = abs(42);
    //@ assert c == 42;
    int d = abs(a);
    int e = abs(-997);

}