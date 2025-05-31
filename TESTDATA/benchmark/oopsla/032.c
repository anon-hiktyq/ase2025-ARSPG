

void foo(int b,int j) {
  int k = 100;
  int i = j;
  int n = 0;
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  /*@ assert i ==j;*/
}
