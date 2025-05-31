

/*@

ensures *a == \old(*b)&&*b == \old(*a);

*/

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*@

ensures \result == 0;

*/

int main20()
{
    int a = 37;
    int b = 91;
    swap(&a, &b);
    //@ assert a == 91;
    //@ assert b == 37;
    return 0;
}