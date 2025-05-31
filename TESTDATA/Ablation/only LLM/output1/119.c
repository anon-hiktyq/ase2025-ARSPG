
void foo(int size) {
 
    int i = 1;
    int sn = 0;
    
    /*@ 
      loop invariant sn == i - 1;
      loop invariant 1 <= i <= size + 1;
      loop variant size - i;
    */
    while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@ assert (sn != 0) ==> (sn == size);*/
  
}
