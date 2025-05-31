
int unknown1();
int unknown2();
int unknown3();

void foo(int pvlen){
  
  int t;
  int k = 0;
  int n;
  int i = 0;

 
  
            /*@
          loop invariant  ((i == 0)&&(k == 0)&&(pvlen == \at(pvlen, Pre))) || 
                         (pvlen >= \at(pvlen, Pre) && pvlen >= i && i >= 0);
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

 
  
            /*@
          loop invariant k == i && i >= 0;
          loop invariant pvlen >= \at(pvlen, Pre);
            */
            while (unknown2()) {
    t = i;
    i = i + 1;
    k = k + 1;
  }
            
  
            /*@
          loop invariant i == \at(i, LoopEntry);
          loop invariant k == \at(k, LoopEntry);
          loop invariant pvlen >= \at(pvlen, Pre);
            */
            while (unknown3()){
      ;
  }
            

  int j = 0;
  n = i;
  
  /*@
    loop invariant k + j == n;
    loop invariant 0 <= j <= n;
    loop invariant k == n - j;
    loop invariant i == n - j;
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
