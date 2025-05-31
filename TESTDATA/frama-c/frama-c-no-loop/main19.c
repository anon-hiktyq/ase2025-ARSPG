

/*@
    requires \valid(a); // Ensure the pointer 'a' is valid.
    requires \valid(b); // Ensure the pointer 'b' is valid.
    ensures *b == 0 ==> *a == \old(*a); // If *b is 0, 'a' remains unchanged.
    ensures *b != 0 ==> *a == 0; // If *b is non-zero, 'a' is reset to 0.
*/
void reset_1st_if_2nd_is_true(int* a, int const* b){
    if(*b) *a = 0 ;
}
int main19(){
    int a = 5 ;
    int x = 0 ;
    reset_1st_if_2nd_is_true(&a, &x);
    //@ assert a == 5 ;
    //@ assert x == 0 ;

    int const b = 1 ;
    reset_1st_if_2nd_is_true(&a, &b);
    //@ assert a == 0 ;
    //@ assert b == 1 ;
    return 0;
}