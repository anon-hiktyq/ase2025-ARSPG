
int fun17(int n) {
    int i = 7;
    int x = 1;

    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}

int main17() {
    int a = fun17(10);
    //@ assert a == 3;
}