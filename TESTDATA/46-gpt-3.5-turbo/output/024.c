
void foo(int n)  {
  int i,j,k;
  
  i=0;
  
            
            /*@
          loop invariant (0<\at(n, Pre)) ==> (((i == 0)&&(n == \at(n, Pre))) || (i == 0 && j >= i && j < n));
          loop invariant !(0<\at(n, Pre)) ==> ((i == 0)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
            */
            for (i=0;i<n;i++){

    j=i;
    
            
            /*@
          loop invariant 0 <= i < n;
          loop invariant i <= j < n;
          loop invariant j <= k && k < n; // Fixed invariant
            */
            for (j=i;j<n;j++){

      k=j;
      
            
            /*@
          loop invariant 0 <= i < n;
          loop invariant i <= j < n;
          loop invariant j <= k && k < n; // Fixed invariant
          loop invariant k >= j;
            */
            for (k=j;k<n;k++){
	       /*@assert k >= i;*/
      }
            
    }
            
  }
   