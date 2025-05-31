
void foo(int n)  {
  int i,j,k;
  
  i=0;
  
            /*@
          loop invariant 0 <= i;
          loop invariant n == \at(n, Pre);
            */
            for (i=0;i<n;i++){

    j=i;
    
            /*@
          loop invariant 0 <= n == \at(n, Pre);
          loop invariant 0 <= i <= n;
          loop invariant i <= j;
            */
            for (j=i;j<n;j++){

      k=j;
      
            /*@
          loop invariant 0 <= n == \at(n, Pre);
          loop invariant 0 <= i <= n;
          loop invariant i <= j <= n;
          loop invariant j <= k <= n;
            */
            for (k=j;k<n;k++){
	       /*@assert k >= i;*/
      }
            
    }
            
  }
            
}
