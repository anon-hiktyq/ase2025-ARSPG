
void foo() {
    int i, j;
    i = 1;
    j = 10;
    
    
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }
    
    /*@ assert j == 6; */
    return 0;
}
