
void foo() {

  int i, c;
  i = 0;
  c = 0;
 
    /*@
      loop invariant  ((c == 0)&&(i == 0)) || (0 <= i <= 1000);
      loop invariant  ((c == 0)&&(i == 0)) || (c == (i * (i - 1)) / 2);
    */
            while (i < 1000) {
    c = c + i;
    i = i + 1;
  }
            
  /*@ assert c >= 0; */
}
