

int test(int x) {
    int a = x;
    int y = 0;

    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
    return y;
}
    
int main7() {
    int num = test(3);
    //@ assert num == 3;
    return 0;
}