
int unknown();
/*@ requires n > 0; */
void foo(int n)   
    {
    int c = 0;
                
                /*@
          loop invariant ((c == 0)&&(n == \at(n, Pre))) || (c > 0 && c <= n);
          loop invariant n == \at(n, Pre);
                */
                while (unknown()){
        
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }
    }
                
           
    /*@ assert  (c == n) ==> (c <= n); */
}
