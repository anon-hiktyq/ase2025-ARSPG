
void arrayAbs(int a[3]) {
    int i = 0;
   
    //@ ghost int a_l[3];
    /*@ 
      ghost for (int k = 0; k < 3; k++) {
        a_l[k] = a[k];
      }
    */
            
    /*@      loop invariant a == \at(a, Pre);
    */
    while (i < 3) {
      if (a[i] < 0) {
        a[i] = -a[i];
      }
      i++;
    }
}
