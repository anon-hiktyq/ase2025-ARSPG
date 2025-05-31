/*@
requires \valid(a);
requires \valid(b);
requires \separated(a,b);

ensures *a == *b;
*/
int foo(int * a,int *b){
    a = b;
    /*@ assert *(a) == *(b); */
    /*@ assert a == b; */
    return 0;
}
