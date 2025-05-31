

/*@

ensures \old(*c) <= \old(*a) && \old(*b) <= \old(*a) && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*a);

ensures \old(*c) <= \old(*b) && \old(*b) > \old(*a) && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*b);

ensures \old(*c) > \old(*b) && \old(*b) > \old(*a) && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*c);

ensures \old(*c) > \old(*a) && \old(*b) <= \old(*a) && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*c);

*/

void max3 (int * a, int * b, int * c)
{

    int max = *a;
    if (*b > max) {
        max = *b;
    }
    if (*c > max) {
        max = *c;
    }
    *c = max; 


}