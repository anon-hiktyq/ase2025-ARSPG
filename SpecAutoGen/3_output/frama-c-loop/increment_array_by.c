
void increment_array_by(int* arr, int n, int c) {
    
            
            /*@
          loop invariant (!(i < \at(n, Pre))) ==> ((c == \at(c, Pre))&&(n == \at(n, Pre))&&(arr == \at(arr, Pre)));
          loop invariant c == \at(c, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr == \at(arr, Pre);
            */
            for (int  i = 0; i < n; i++) {
        arr[i] = arr[i] + c;
    }
            
}
