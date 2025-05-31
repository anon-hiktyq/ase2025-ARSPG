
void foo(int n,int y,int v1,int v2,int v3) {
    
    int x = 1;

            /*@          loop invariant v3 == \at(v3, Pre);
          loop invariant v2 == \at(v2, Pre);
          loop invariant v1 == \at(v1, Pre);
          loop invariant n == \at(n, Pre);
            */
            while (x <= n) {
        y = n - x;
        x = x + 1;
    }
            

    /*@ assert (n > 0) ==> (y <= n); */
}
