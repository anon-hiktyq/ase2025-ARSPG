
int unknown();

void foo()  
{
    int c = 0;
  
    /*@
      loop invariant  ((c == 0)) || (c >= 0 && c <= 40);
    */
    while (unknown()) {
        if (unknown()) {
            if (c != 40) {
                c  = c + 1;
            }
        } else {
            if (c == 40) {
                c  = 1;
            }
        }
    }

    /*@ assert (c != 40) ==> (c >= 0);*/
}
