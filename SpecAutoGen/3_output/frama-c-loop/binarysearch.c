
int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    
            
            /*@
          loop invariant low >= -1 && high <= n; 
          loop invariant (-1+1 < \at(n, Pre)) ==> (((high == \at(n, Pre))&&(low == -1)&&(n == \at(n, Pre))&&(x == \at(x, Pre))&&(a == \at(a, Pre))) || (low >= -1));
          loop invariant (-1+1 < \at(n, Pre)) ==> (high <= n) ;
          loop invariant (!(-1+1 < \at(n, Pre))) ==> ((high == \at(n, Pre))&&(low == -1)&&(n == \at(n, Pre))&&(x == \at(x, Pre))&&(a == \at(a, Pre)));
          loop invariant n == \at(n, Pre);
          loop invariant x == \at(x, Pre);
          loop invariant a == \at(a, Pre);
            */
            while (low+1 < high) {
        p = (low + high) / 2;
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
            low = p;
            else high = p;
    }
            
    return -1;
}
