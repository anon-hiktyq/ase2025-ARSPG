

void arrayAbs(int a[3]) {
    int i = 0;
   
    while (i < 3) {
      if (a[i] < 0) {
        a[i] = -a[i];
      }
      i++;
    }
    
   

}
  
  void main5() {
    int arr[3] = {1, -2, 3};
    arrayAbs(arr);
    /*@
    assert \forall i; 0 < i < 3 ==> \at(a[i],Pre) < 0 && (a[i] == -\at(a{i],Pre));
    */
}