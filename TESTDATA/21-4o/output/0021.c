
/*@ 
    loop invariant 0 <= i && i <= n;
    loop invariant k == n;
*/
for (i = 0; i < n; i++) {
        
    j = 2 * i;

    /*@ 
        loop invariant 2 * i <= j && j <= n;
        loop invariant 0 <= i && i < n;
    */
    for (j = 2 * i; j < n; j++) {
        if (unknown1()) {
            /*@ 
                loop invariant 2 * i <= k && k <= n;
                loop invariant 0 <= i && i < n;
                loop invariant 2 * i <= j && j < n;
            */
            for (k = j; k < n; k++) {
                /*@ assert k >= 2 * i; */
            }
        } else {
            /*@ assert k == n; */
        }
    }
                
    /*@ 
        loop invariant (n < INT_MAX && k == n) ==> ((0 < n) ==> (((i == 0)&&(n == n)&&(k == k)) || ((i == i)&&(k == k)&&(n == n))));
        loop invariant (n < INT_MAX && k == n) ==> ((0 < n) ==> (((i == 0)&&(n == n)&&(k == k)) || ((i == i)&&(n == n)&&(k == k))));
        loop invariant (n < INT_MAX && k == n) ==> ((!(0 < n)) ==> ((i == 0)&&(n == n)&&(k == k)));
        loop invariant (n < INT_MAX && k == n) ==> (n == n);
    */
}
