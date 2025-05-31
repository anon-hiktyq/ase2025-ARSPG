
void foo(int A[2048]) {
  int i = 0;
  
  
                
                /*@
          loop invariant  ((i == 0)&&(A == \at(A, Pre))) || ((0 <= i <= 1024) && (\forall integer j; 0 <= j < i ==> A[j] == j)) ;
          loop invariant A == \at(A, Pre);
                */
                for (i = 0; i < 1024; i++) {
    A[i] = i;
  }
                

  /*@ assert A[1023] == 1023; */
}
