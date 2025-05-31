
void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 
 while(i < n) {
  j = 0;
  
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : 1 < \at(n, Pre) && (j == 0) * (i == 1) * (k == 1) * (n == \at(n, Pre)) <<< */
    
            /*@
          loop invariant n == \at(n, Pre);
          loop invariant k == 1 + ((i-1)*i*(i+1))/6;
          loop invariant 1 <= i && i < n;
          loop invariant j == 0;
            */
            while(j < i) {
      k += (i-j);
      j++;
  }
            
  i++;
 }
 /*@ assert k >= n */;
 
}
