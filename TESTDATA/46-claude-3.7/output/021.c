
int unknown();
/*@
requires n > 0;
requires n < 10;
*/
void foo(int n,int j,int v) {
  int c1 = 4000;
  int c2 = 2000;
  int i = 0;
  int k = 0;
 
  
            
            /*@
          loop invariant  (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(j == \at(j, Pre))&&(n == \at(n, Pre))) || ((v == 0 || v == 1)))) ;
          loop invariant  (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(j == \at(j, Pre))&&(n == \at(n, Pre))) || ((1 <= i <= n)))) ;
          loop invariant  (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(j == \at(j, Pre))&&(n == \at(n, Pre))) || ((k >= i * c2)))) ;
          loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> ((!(0 < \at(n, Pre))) ==> ((k == 0)&&(i == 0)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(j == \at(j, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> (c2 == 2000);
          loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> (c1 == 4000);
          loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> (j == \at(j, Pre));
          loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 10) ==> (n == \at(n, Pre));
            */
            while( i < n ) {
    i++;
    if(unknown2() % 2 == 0) {
        v = 0;
    }
    else v = 1;
    
    if( v == 0 ){
      k += c1;
    }else {
      k += c2;
    }
  }
            
  
  /*@ assert k > n; */
}
