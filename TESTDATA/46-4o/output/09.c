
int unknown1();
int unknown2();
int unknown3();

void foo(int pvlen){
  
  int t;
  int k = 0;
  int n;
  int i = 0;

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (i == 0) * undef_data_at(&n) * (k == 0) * undef_data_at(&t) * (pvlen == \at(pvlen, Pre)) <<< */
    
  /*@
    loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (pvlen >= i);
    loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (i <= pvlen);
    loop invariant k == 0;
  */
  while (unknown1()){
    i = i + 1;
  
    if (i > pvlen) {
      pvlen = i;
    }
  }
            
  i = 0;

  
            
    /*@
      loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (k == i);
      loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (i >= 0);
      loop invariant k >= 0;
    */
    while (unknown2()) {
      t = i;
      i = i + 1;
      k = k + 1;
    }
            
  
            
    /*@
      loop invariant i >= 0;
      loop invariant k >= 0;
      loop invariant pvlen >= \at(pvlen, Pre);
    */
    while (unknown3()){
      ;
    }
            

  int j = 0;
  n = i;
  
  
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : exists retval_52, retval_52 == 0 && retval_52 <= INT_MAX && retval_52 > INT_MIN && retval_50 == 0 && retval_50 <= INT_MAX && retval_50 > INT_MIN && retval_48 == 0 && retval_48 <= INT_MAX && retval_48 > INT_MIN && (j == 0) * (i == 0) * (n == 0) * (k == 0) * undef_data_at(&t) * (pvlen == \at(pvlen, Pre)) <<< */
    
            /*@
          loop invariant  ((j == 0)&&(i == 0)&&(n == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (k + j <= n && k >= 0) ;
          loop invariant  ((j == 0)&&(i == 0)&&(n == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (i >= 0) ;
          loop invariant  ((j == 0)&&(i == 0)&&(n == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (j >= 0) ;
          loop invariant n == i + j;
          loop invariant pvlen == \at(pvlen, Pre);
            */
            while (1) {
    k = k - 1;
    i = i - 1;
    j = j + 1;
    if (j < n) {
    } else {
      break;
    }
    /*@ assert k >= 0; */
  }
            
}
