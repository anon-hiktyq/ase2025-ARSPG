int func11(int n) {
    int sum = 0;
    int i = 0;

    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}

// write a test
void main11() {
    int t = func11(10);
    //@ assert t == 30;
}