
void foo(int n,int y) {
    
    int x = 1;

    
            /*@
          loop invariant (1 <= n) ==> ((x == 1) && (y == \at(y, Pre)) && (n == \at(n, Pre))) || (n - x <= y <= n); 
          loop invariant (1 <= n) ==> ((x == 1) && (y == \at(y, Pre)) && (n == \at(n, Pre))) || (0 <= y);
          loop invariant (1 <= n) ==> (x <= n + 1);
          loop invariant n == \at(n, Pre);
            */
            while (x <= n) {
        y = n - x;
        x = x + 1;
    }
            

    /*@ assert (n > 0) ==> (y >= 0); */
}
