
void foo(int tmp,int A[2048],int B[2048]) {


  int i =0;
  
                
                /*@
          loop invariant  (2048 == 2048) ==> (((i == 0)&&(2048 == 2048)&&(B == \at(B, Pre))&&(A == \at(A, Pre))&&(tmp == \at(tmp, Pre))) || ((0 < i <= 2048) && tmp == A[i-1] && \forall integer k; 0 <= k < i ==> B[k] == A[k])) ;
          loop invariant  (2048 == 2048) ==> (((i == 0)&&(2048 == 2048)&&(B == \at(B, Pre))&&(A == \at(A, Pre))&&(tmp == \at(tmp, Pre))) || (0 < i <= 2048)) ;
          loop invariant (2048 == 2048) ==> (2048 == 2048);
          loop invariant (2048 == 2048) ==> (B == \at(B, Pre));
          loop invariant (2048 == 2048) ==> (A == \at(A, Pre));
                */
                for (i = 0; i < 2048; i++) {
    tmp = A[i];
    B[i] = tmp;
  }
                

 /*@assert A[1024] == B[1024];*/

}
