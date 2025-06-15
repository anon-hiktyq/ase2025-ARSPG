
/*@
    requires base > 0; 
    requires height > 0; 
    ensures \result == (base * height) / 2; 
    ensures \result >= 0; 
*/
int area(int base, int height){
    int res = (base * height) / 2;
    return res;
}

/*@
    ensures \result == 0; 
*/
int main3() {
    int a = area(4, 5);
    //@ assert a == 10;
    return 0;
}
