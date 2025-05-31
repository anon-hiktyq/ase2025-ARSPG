
void ArrayAbs(int arr[3]){
    int i=0;
    
    /*@
      logic integer arr_l[3] = \at(arr, Pre);
    */
    
    /*@
      loop invariant (\forall integer j; 0 <= j < i ==> arr[j] >= 0 && (arr[j] == arr_l[j] || arr[j] == -arr_l[j])) && (\forall integer j; i <= j < 3 ==> arr[j] == arr_l[j]);
      loop invariant 0 <= i <= 3;
      loop invariant arr == \at(arr, Pre);
    */
    for(; i < 3 ; i++ ){
        if( arr[i]<0 ){
            arr[i] = -arr[i];
        }
    }
}
