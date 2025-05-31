
typedef struct __TripleFabsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleFabsMax;

/*@
    requires \valid(arr + (0 .. 2)); // Ensure the pointer 'arr' is valid for the array range
    ensures \forall integer i; 0 <= i < 3 ==> arr[i] >= 0; // Ensure all elements in the array are non-negative
*/
void ArrayAbs(int arr[3]){
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= 0;
      loop invariant (!(i < 3)) ==> ((arr == \at(arr, Pre)));
      loop invariant arr == \at(arr, Pre);
      loop variant 3 - i; // Strictly decreasing loop variant
    */
    for( int i = 0; i < 3; i++ ){
        if( arr[i] < 0 ){
            arr[i] = -arr[i];
        }
    }
}
