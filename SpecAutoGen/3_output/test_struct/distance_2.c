int distance_2(struct Point* p1, struct Point *p2) 
{
    int dx = *(p2->x) - *(p1->x);
    int dy = *(p2->y) - *(p1->y);
    return dx * dx + dy * dy;
}