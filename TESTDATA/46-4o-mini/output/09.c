int unknown1();
int unknown2();
int unknown3();

void foo(int pvlen){
  
  int t;
  int k = 0;
  int n;
  int i = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (0 <= i <= pvlen) ;
          loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || (i >= 0) ;
          loop invariant k == 0;
        */
        while (unknown1()){
    i = i + 1;
  
  if (i > pvlen) {
    pvlen = i;
  } else {

  }
}
                
  i = 0;

 
  while (unknown2()) {
    t = i;
    i = i + 1;
    k = k + 1;
  }
  while (unknown3()){
      ;
  }

  int j = 0;
  n = i;
  
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