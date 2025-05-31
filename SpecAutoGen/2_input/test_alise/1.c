
int main() {
    int a = 10;
    int *p1 = &a; // p1 是 a 的别名
    int *p2 = &a; // p2 也是 a 的别名
    /*@ assert p1 == p2;*/
    return 0;
}