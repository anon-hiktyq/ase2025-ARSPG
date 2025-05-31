void foo(int n)
{
  int k=1;
  int i=1;
  int j=0;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (j == 0) && (i == 1) && (k == 1) && (n == \at(n, Pre)) <<< */
  
  /*@
    loop invariant n == \at(n, Pre);
    loop invariant k >= 1;
    loop invariant 1 <= i;
  */
  while(i < n) {
    j = 0;
    
    /*@
      loop invariant n == \at(n, Pre);
      loop invariant k >= 1;
      loop invariant 0 <= j <= i;
    */
    while(j < i) {
        k += (i-j);
        j++;
    }
    
    i++;
  }
  
  /*@ assert k >= n; */
}