
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
          loop invariant  (\at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (i % 2 == 0 && i >= 0)) ;
          loop invariant  (\at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((j == 1)&&(i == 0)&&(flag == \at(flag, Pre))) || (j >= 1 && j >= i / 2 + 1)) ;
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

  
            
            /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : exists retval_55, retval_55 == 0 && retval_55 <= INT_MAX && retval_55 > INT_MIN && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => j == 1 && i == 0 && flag == \at(flag, Pre) || i % 2 == 0 && i >= 0) && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => j == 1 && i == 0 && flag == \at(flag, Pre) || j >= 1 && j >= i / 2 + 1) && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => flag == \at(flag, Pre)) && \at(flag, Pre) != 0 && \at(flag, Pre) > 0 && (b == 0) * (a == 0) * undef_data_at(&k) <<< */
    
            /*@
          loop invariant  (j >= 1 && j >= i / 2 + 1) && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => flag == \at(flag, Pre)) && \at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((b == 0)&&(a == 0)) || (a >= 0 && b == a + (j - i))) ;
          loop invariant  (j >= 1 && j >= i / 2 + 1) && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => flag == \at(flag, Pre)) && \at(flag, Pre) != 0 && \at(flag, Pre) > 0) ==> (((b == 0)&&(a == 0)) || (b >= a + (j - i))) ;
          loop invariant (i % 2 == 0 && i >= 0) && (\at(flag, Pre) != 0 && \at(flag, Pre) > 0 => j == 1 && i == 0) ==> (flag == \at(flag, Pre));
          loop invariant flag == \at(flag, Pre);
            */
            while (unknown2()) {
    a++;
    b += (j - i);
  }
            
  /*@ assert (flag!= 0) ==> (a==b); */
}
