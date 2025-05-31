

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
/*@

ensures \old(*c) > \old(*a) && \old(*b) <= \old(*a) && a == a && b == b && c == c && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*c);

ensures \old(*c) > \old(*b) && \old(*b) > \old(*a) && a == a && b == b && c == c && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*c);

ensures \old(*c) <= \old(*b) && \old(*b) > \old(*a) && a == a && b == b && c == c && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*b);

ensures \old(*c) <= \old(*a) && \old(*b) <= \old(*a) && a == a && b == b && c == c && a == \old(a) && b == \old(b) && c == \old(c) ==> *a == \old(*a)&&*b == \old(*b)&&*c == \old(*a);

*/

void foo(int *a, int *b, int *c)
{
    max3(a,b,c);
}