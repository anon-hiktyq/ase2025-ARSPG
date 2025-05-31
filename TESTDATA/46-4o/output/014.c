
int unknown();

/*@ requires m > 0;*/
void foo(int m) {
  int a = 0;
  
  int j = 1;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
  >>> PRECONDITION OF THE LOOP : \at(m, Pre) > 0 && (j == 1) * (a == 0) * (m == \at(m, Pre)) <<< */
  
  /*@
    loop invariant 1 <= j <= m + 1;
    loop invariant -j + 1 <= a <= j - 1;
    loop invariant m > 0;
  */
  for(j = 1; j <= m; j++){
    if(unknown()) 
      a++;
    else
      a--; 
  }
  
  /*@ assert a >= -m && a <= m;*/
}
