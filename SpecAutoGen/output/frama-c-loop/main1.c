

/*@
  requires \valid(a + (0 .. n-1)); 
  requires n > 0; 
  ensures \forall integer j; 0 <= j < n ==> \result >= a[j]; 
  ensures \exists integer j; 0 <= j < n && \result == a[j]; 
*/
int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];

  /*@
    loop invariant \forall integer j; 0 <= j < i ==> a[j] <= max;
    loop invariant 1 <= i <= n;
    loop invariant \exists integer j; 0 <= j < i && max == a[j];
    loop assigns i, max;
    loop variant n - i;
  */
  while (i < n) {
    if (max < a[i])
      max = a[i];
    i = i + 1;
  }

  return max;
}

void main1() {
  int arr[5] = {1, 2, 3, 4, 5};
  int max = arraymax(arr, 5);
  //@ assert max >= arr[0];
  //@ assert max >= arr[1];
  //@ assert max >= arr[2];
  //@ assert max >= arr[3];
  //@ assert max >= arr[4];
}