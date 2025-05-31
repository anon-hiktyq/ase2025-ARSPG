
int mul10(int a, int b) {
    int x = a, y = b, prod = 0;

    while(x >= 0) {
        prod = prod + y;
        x--;
    }
    return prod;
}

int main10() {
    int pdt = mul10(2, 5);
    //@ assert pdt == 10;
}