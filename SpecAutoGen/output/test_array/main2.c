

/*@

ensures \result == a[0] ;

*/

int arrayHead(int *a) 
{
    int i = 1;
    int max = a[0];
    return max;
  }
/*@

ensures \result == a_l[0] ;

*/

int main2() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int head = arrayHead(arr);
    return head;
}