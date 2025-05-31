
int unknown1();
int unknown2();
int unknown3();

void foo(int pvlen) {

  int t;
  int k = 0;
  int n;
  int i = 0;

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (i == 0) * undef_data_at(&n) * (k == 0) * undef_data_at(&t) * (pvlen == \at(pvlen, Pre)) <<< */
    
  /*@
    loop invariant  k >= 0;
    loop invariant  pvlen >= 0; 
    loop invariant  (0 <= i);
    */
  while (unknown1()) {
    i = i + 1;

    if (i > pvlen) {
      pvlen = i;
    } else {

    }
  }

  i = 0;

  /*@
          loop invariant  (0 <= i);
          loop invariant  (k >= 0);
          loop invariant  (pvlen >= 0);
            */
  while (unknown2()) {
    t = i;
    i = i + 1;
    k = k + 1;
  }

  /*@
          loop invariant  (i >= 0) && (k >= 0) && (pvlen >= 0);
          loop invariant  (i >= 0) || (k >= 0);
          loop invariant  (pvlen >= 0);
            */
  while (unknown3()) {
    ;
  }

  int j = 0;
  n = i;

  /*@
          loop invariant  ((j == 0)&&(i >= 0)&&(n >= 0)&&(k == 0)&&(pvlen >= 0)) || (i >= 0);
          loop invariant  ((j == 0)&&(i >= 0)&&(n >= 0)&&(k == 0)&&(pvlen >= 0)) || (j >= 0);
          loop invariant  ((j == 0)&&(i >= 0)&&(n >= 0)&&(k == 0)&&(pvlen >= 0)) || (i >= 0) ;
          loop invariant n >= 0; 
          loop invariant pvlen >= 0; 
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
