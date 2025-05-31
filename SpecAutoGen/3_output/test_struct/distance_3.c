int distance_3(struct TwoPoint * tp) 
{
    int dx = (tp->p1->x) - (tp->p2->x);
    int dy = (tp->p1->y) - (tp->p2->y);

    return dx * dx + dy * dy;
}