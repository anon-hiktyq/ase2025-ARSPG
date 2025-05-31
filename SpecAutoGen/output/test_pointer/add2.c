

/*@

ensures (*(\old(b)) != *(\old(r)) && *(\old(a)) != *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> (*a == *(\old(a))&&*b == *(\old(b))&&*r == *(\old(r)));
ensures (*(\old(b)) != *(\old(r)) && *(\old(a)) != *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> ( \result == *(\old(a)) + *(\old(b)) + *(\old(r)) );

ensures (*(\old(b)) == *(\old(r)) && *(\old(a)) != *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> (*a == *(\old(a))&&*b == *(\old(b))&&*r == *(\old(r)));
ensures (*(\old(b)) == *(\old(r)) && *(\old(a)) != *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> ( \result == *(\old(a)) );

ensures (*(\old(a)) == *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> (*a == *(\old(a))&&*b == *(\old(b))&&*r == *(\old(r)));
ensures (*(\old(a)) == *(\old(r)) && *(\old(a)) != *(\old(b)) ) ==> ( \result == *(\old(b)) );

ensures (*(\old(a)) == *(\old(b)) ) ==> (*a == *(\old(a))&&*b == *(\old(b))&&*r == *(\old(r)));
ensures (*(\old(a)) == *(\old(b)) ) ==> ( \result == *(\old(r)) );

*/

int add2(int *a, int *b, int *r) 
{
    if (*a == *b) return *r;
    else if (*a == *r) return *b;
    else if (*b == *r) return *a;
    else return *a + *b + *r;
}