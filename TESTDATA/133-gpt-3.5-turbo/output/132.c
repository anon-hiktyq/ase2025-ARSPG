
int unknown();
void foo(int j,int c,int t) {

    int i = 0;




            
            /*@
          loop invariant  ((i == 0)&&(t == \at(t, Pre))&&(c == \at(c, Pre))&&(j == \at(j, Pre))) || (j >= 0);
          loop invariant  ((i == 0)&&(t == \at(t, Pre))&&(c == \at(c, Pre))&&(j == \at(j, Pre))) || (t >= 0);
          loop invariant  ((i == 0)&&(t == \at(t, Pre))&&(c == \at(c, Pre))&&(j == \at(j, Pre))) || (i == j + t);
          loop invariant c == \at(c, Pre);
            */
            while(unknown()) {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }
    }
             
 /*@ assert i >= 0; */


}
