int factorial9(int n) {

  int i = 1;
  int f = 1;

  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}

// write a test
void main9() {
  int t = factorial9(5);
  //@ assert t == 120;
}