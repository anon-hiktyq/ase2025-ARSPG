struct Point {
    int *x;
    int *y;
};

/*@

ensures *p1->x == *\old(p1->x)&&*p1->y == *\old(p1->y)&&*p2->x == *\old(p2->x)&&*p2->y == *\old(p2->y);
ensures \result == (*\old(p2->x) - *\old(p1->x)) * (*\old(p2->x) - *\old(p1->x)) + (*\old(p2->y) - *\old(p1->y)) * (*\old(p2->y) - *\old(p1->y)) ;

*/

int distance_2(struct Point* p1, struct Point *p2) 

{
    int dx = *(p2->x) - *(p1->x);
    int dy = *(p2->y) - *(p1->y);
    return dx * dx + dy * dy;
}