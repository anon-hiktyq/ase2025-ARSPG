
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
