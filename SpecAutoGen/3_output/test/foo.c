void foo(int *a, int *b, int *c){
    
    while(*a < 0){          
        *a = *a + 1;
    }   
    max3(a,b,c);
}