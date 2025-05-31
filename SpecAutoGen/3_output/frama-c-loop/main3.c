

/*@
 requires   n > 0 && n < 100 ;

ensures Results(\result);

*/

int func3(int *a, int n, int x, int *sum) 
{
    int p = 0;
    int count = 0;
    *sum = 0;

    /* >>> LOOP INVARIANT FIXED <<< */

    /*@
        loop invariant \valid(a + (0 .. n - 1));
        loop invariant 0 <= p <= n;
        loop invariant count >= 0;
        loop invariant *sum >= 0;
        loop invariant \forall integer i; 0 <= i < p ==> (a[i] == x ==> count == (\at(count, Pre) + (\sum(0, p - 1, \lambda j; (a[j] == x ? 1 : 0)))));
        loop invariant \forall integer i; 0 <= i < p ==> (a[i] == x ==> *sum == (\at(sum, Pre) + (\sum(0, p - 1, \lambda j; (a[j] == x ? x : 0)))));
        loop variant n - p;
    */
    while (p < n) {
        if (a[p] == x) {
            count = count + 1;
            *sum = *sum + x;
        }
        p = p + 1;
    }

    *sum += 0;

    return count;
}

void main3() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    int count = func3(arr, 5, 3, &sum);
    //@ assert sum == count*3;
}