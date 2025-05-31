

/*@

ensures *\old(b) > *\old(c) && *\old(a) <= *\old(c) && *\old(a) <= *\old(b) ==> *a == *\old(a)&&*b == *\old(c)&&*c == *\old(b);

ensures *\old(b) > *\old(a) && *\old(a) > *\old(c) && *\old(a) <= *\old(b) ==> *a == *\old(c)&&*b == *\old(a)&&*c == *\old(b);

ensures *\old(b) <= *\old(a) && *\old(a) > *\old(c) && *\old(a) <= *\old(b) ==> *a == *\old(c)&&*b == *\old(b)&&*c == *\old(a);

ensures *\old(a) <= *\old(a) && *\old(a) > *\old(c) && *\old(a) > *\old(b) ==> *a == *\old(c)&&*b == *\old(a)&&*c == *\old(a);

ensures *\old(a) <= *\old(c) && *\old(a) <= *\old(c) && *\old(a) > *\old(b) ==> *a == *\old(a)&&*b == *\old(a)&&*c == *\old(c);

ensures *\old(b) <= *\old(c) && *\old(a) <= *\old(c) && *\old(a) <= *\old(b) ==> *a == *\old(a)&&*b == *\old(b)&&*c == *\old(c);

*/

void order_3(int *a, int *b, int *c) 
{
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