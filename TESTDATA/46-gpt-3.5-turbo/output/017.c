
void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 
            /* >>> LOOP INVARIANT TO FILL <<< 
               >>> PRECONDITION OF THE LOOP : (j == 0) * (i == 1) * (k == 1) * (n == \at(n, Pre)) <<< */
    
            /*@
          loop invariant (1 < \at(n, Pre)) ==> (((j == 0)&&(i == 1)&&(k == 1)&&(n == \at(n, Pre))) || (k == 1 + (i - 1) * i / 2));
          loop invariant (1 < \at(n, Pre)) ==> (((j == 0)&&(i == 1)&&(k == 1)&&(n == \at(n, Pre))) || (i <= n));
          loop invariant (1 < \at(n, Pre)) ==> (((j == 0)&&(i == 1)&&(k == 1)&&(n == \at(n, Pre))) || (0 <= j && j <= i));
          loop invariant (!(1 < \at(n, Pre))) ==> ((j == 0)&&(i == 1)&&(k == 1)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
            */
            while(i < n) {
  j = 0;
  
            /*@
          loop invariant 1 <= n ;
          loop invariant k == 1 + (i - 1) * i / 2 ;
          loop invariant i <= n ;
          loop invariant 0 <= j && j <= i ;
            */
            while(j < i) {
      k += (i-j);
      j++;
  }
            
  i++;
 }
            
 /*@ assert k >= n */;
 
}
