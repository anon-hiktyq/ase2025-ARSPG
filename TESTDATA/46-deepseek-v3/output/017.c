
void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 
 
            /*@
          loop invariant (1 < n) ==> (((j == 0) && (i == 1) && (k == 1)) || (k == (i * (i + 1)) / 2));
          loop invariant (1 < n) ==> (((j == 0) && (i == 1) && (k == 1)) || (1 <= i && i <= n));
          loop invariant (1 < n) ==> (((j == 0) && (i == 1) && (k == 1)) || (j == 0));
          loop invariant (!(1 < n)) ==> ((j == 0) && (i == 1) && (k == 1));
          loop invariant n == n;
            */
            while(i < n) {
  j = 0;
  
            /*@
          loop invariant 1 <= i && i <= n;
          loop invariant k == (i * (i + 1)) / 2;
          loop invariant 0 <= j && j <= i;
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
