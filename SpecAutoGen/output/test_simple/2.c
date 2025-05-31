
int main() {
    int a = 10;
    int * p1 = &a; 
    int * p2 = &a; 
    
    /*@ assert p1 == p2;*/
    return 0;
}