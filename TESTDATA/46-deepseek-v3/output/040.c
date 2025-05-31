
int unknown1();
int unknown2();

/*@
requires flag > 0;
*/
void foo(int flag) {
  int i, j, k;
  j = 1;
  if (flag) {
    i = 0;
  } else {
    i = 1;
  }

  
            
            /*@
          loop invariant  (\at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (j == i + 1)) ;
          loop invariant  (\at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (i >= 2 && i % 2 == 0)) ;
          loop invariant (\at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (flag == \at(flag, Pre));
            */
            while (unknown1()) {
    i += 2;
    if (i % 2 == 0) {
      j += 2;
    } else j++;
  }
            

  int a = 0;
  int b = 0;

  
            
            /*@
          loop invariant  ((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (a == b) ;
          loop invariant  ((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (b == a) ;
          loop invariant j == i + 1;
          loop invariant i >= 0;
          loop invariant flag == \at(flag, Pre);
            */
            while (unknown2()) {
    a++;
    b += (j - i);
  }
            
  /*@ assert (flag!= 0) ==> (a==b); */
}
