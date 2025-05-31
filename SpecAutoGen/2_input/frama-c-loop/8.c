
int func8(int c) {
    int x = c;
    int y = 0;

    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}

// write a test
void main8() {
    int t = func8(5);
    //@ assert t == 5;
}