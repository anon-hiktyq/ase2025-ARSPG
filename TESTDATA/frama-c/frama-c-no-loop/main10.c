

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

int main10()
{
    int a = 42;
    int b = 37;

    swap(&a, &b);

    //@ assert a == 37 && b == 42;

    return 0;
}