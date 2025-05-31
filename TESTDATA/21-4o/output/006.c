
/*@
requires a < 1000000;
requires 0 <= b && b <= 1000000;
*/
void foo(int a, int b) {

    int res, cnt;
    res = a;
    cnt = b;
    

    
                
                /*@
          loop invariant (\at(b, Pre) > 0) ==> (((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre))) || (res == a + (\at(b, Pre) - cnt)));
          loop invariant (\at(b, Pre) > 0) ==> (((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre))) || (cnt >= 0));
          loop invariant (!(\at(b, Pre) > 0)) ==> ((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre)));
          loop invariant b == \at(b, Pre);
          loop invariant a == \at(a, Pre);
                */
                while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }
                

    /*@ assert res == a + b;*/

}
