int sum7(char n) {
    int s = 0;
    char k = 0;

    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    return (int)s;
}