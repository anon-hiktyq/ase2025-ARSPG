

void foo(int n)  {
  int i,j,k;
  
  i=0;
  for (i=0;i<n;i++){

    j=i;
    for (j=i;j<n;j++){

      k=j;
      for (k=j;k<n;k++){
	       /*@assert k >= i;*/
      }
    }
  }
}
