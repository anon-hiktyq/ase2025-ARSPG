void max3 (int * a, int * b, int * c){

    int max = *a;
    if (*b > max) {
        max = *b;
    }
    if (*c > max) {
        max = *c;
    }
    *c = max; 


}


void foo(int *a, int *b, int *c){
    
    while(*a < 0){          
        *a = *a + 1;
    }   
    max3(a,b,c);
}