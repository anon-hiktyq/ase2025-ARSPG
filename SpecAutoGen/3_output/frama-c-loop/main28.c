int main28() {
    int a = 3;
    int num = fun28(1, 2, &a);
    //@ assert a == 1;
    //@ assert num == 0;
    return 0;
}