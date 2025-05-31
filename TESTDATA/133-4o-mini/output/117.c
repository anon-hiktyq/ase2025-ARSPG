
int unknown();
void foo(int v1,int v2,int v3) {

    int sn = 0;
    int x = 0;

            /*@
          loop invariant  ((x == 0)&&(sn == 0)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))) || (sn == x) ;
          loop invariant  ((x == 0)&&(sn == 0)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))) || (x >= 0) ;
          loop invariant v3 == \at(v3, Pre);
          loop invariant v2 == \at(v2, Pre);
          loop invariant v1 == \at(v1, Pre);
            */
            while (unknown()) {
  
      x  = (x + 1);
      sn  = (sn + 1);
      
    }
            
       /*@ assert (sn != -1) ==> (sn == x);*/
}
