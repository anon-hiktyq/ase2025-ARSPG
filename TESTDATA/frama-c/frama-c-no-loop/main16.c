

/*@

ensures *a == \old(*a) + \old(*b)&&*b == \old(*b);
ensures \result == \old(*a) + \old(*b) ;

*/

int incr_a_by_b(int* a, int * b)
{
    *a += *b;
    return *a;
}
/*@

ensures \exists int retval_70, a_v_69;  retval_70 == 10 + 20  ==> a_v_69 == 10 + 20;

*/

void main16() 
{
    int a = 10;
    int b = 20;
    incr_a_by_b(&a, &b);
    //@ assert a == 30;
    //@ assert b == 20;
}