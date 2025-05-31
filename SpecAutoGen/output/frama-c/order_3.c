
/*@
requires \valid(a) && \valid(b) && \valid(c);
ensures \old(*\old(b)) > \old(*\old(c)) && \old(*\old(a)) <= \old(*\old(c)) && \old(*\old(a)) <= \old(*\old(b)) ==> *\old(a) == \old(*\old(a))&&*\old(b) == \old(*\old(c))&&*\old(c) == \old(*\old(b));
ensures \old(*\old(b)) > \old(*\old(a)) && \old(*\old(a)) > \old(*\old(c)) && \old(*\old(a)) <= \old(*\old(b)) ==> *\old(a) == \old(*\old(c))&&*\old(b) == \old(*a)&&*\old(c) == \old(*\old(b));
ensures \old(*\old(b)) <= \old(*\old(a)) && \old(*\old(a)) > \old(*\old(c)) && \old(*\old(a)) <= \old(*\old(b)) ==> *\old(a) == \old(*\old(c))&&*\old(b) == \old(*b)&&*\old(c) == \old(*\old(a));

ensures \old(*a) <= \old(*\old(a)) && \old(*\old(a)) > \old(*\old(c)) && \old(*\old(a)) > \old(*\old(b)) ==> *\old(a) == \old(*\old(c))&&*\old(b) == \old(*a)&&*\old(c) == \old(*\old(a));

ensures \old(*a) <= \old(*\old(c)) && \old(*\old(a)) <= \old(*\old(c)) && \old(*\old(a)) > \old(*\old(b)) ==> *\old(a) == \old(*a)&&*\old(b) == \old(*a)&&*\old(c) == \old(*\old(c));

ensures \old(*b) <= \old(*c) && \old(*a) <= \old(*c) && \old(*\old(a)) <= \old(*\old(b)) ==> *\old(a) == \old(*a)&&*\old(b) == \old(*b)&&*\old(c) == \old(*\old(c));
*/
void order_3(int *a, int *b, int *c) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {    
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}
