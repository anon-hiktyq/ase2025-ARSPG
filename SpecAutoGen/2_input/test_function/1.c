int area(int base, int height){
    int res = (base * height)/2;
    return res;
}

int main1() {
    int a = area(4, 5);
    //@ assert a == 10;
    return 0;
}
