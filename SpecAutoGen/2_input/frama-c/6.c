
int function(int x, int y) {
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    //@ assert res == \at(x,Pre) + \at(y,Pre) + 5;
    return res ;
}

void main6() {
    int t = function(-5, 5);
    //@ assert t == 5;
}