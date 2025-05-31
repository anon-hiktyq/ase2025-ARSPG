
/*@
requires a < 1000000;
requires 0 <= b && b <= 1000000;
*/
void foo(int a, int b) {
    int res, cnt;
    res = a;
    cnt = b;
    
    /*@ 
        loop invariant  (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> 
                          ((\at(b, Pre) > 0) ==> (((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre))) || 
                          (res == \at(a, Pre) + (\at(b, Pre) - cnt)))) ;
        loop invariant  (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> 
                          ((\at(b, Pre) > 0) ==> (((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre))) || 
                          (cnt == \at(b, Pre) - (res - \at(a, Pre))))) ;
        loop invariant (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> 
                          ((!(\at(b, Pre) > 0)) ==> ((cnt == \at(b, Pre))&&(res == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre))));
        loop invariant (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> (b == \at(b, Pre));
        loop invariant (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> (a == \at(a, Pre));
        loop invariant (\at(a, Pre) < 1000000 && 0 <= \at(b, Pre) && \at(b, Pre) <= 1000000) ==> (res == a + (b - cnt));
    */
    while (cnt > 0) {
        cnt = cnt - 1;
        res = res + 1;
    }

    /*@ assert res == a + b; */
}
