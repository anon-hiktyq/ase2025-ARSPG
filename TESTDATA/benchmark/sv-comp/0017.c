

void foo(int tmp, int A[2048], int B[2048]) {
  int i = 0;
  
  for (i = 0; i < 2048; i++) {
    tmp = A[i];
    B[i] = tmp;
  }

  /*@assert A[1024] == B[1024];*/
}
