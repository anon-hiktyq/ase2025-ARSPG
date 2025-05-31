struct Point {
    int x;
    int y;
};
struct TwoPoint{    
    struct Point p1;
    struct Point p2;

};

/*@

ensures tp->p1.x == \old(tp->p1.x)&&tp->p1.y == \old(tp->p1.y)&&tp->p2.x == \old(tp->p2.x)&&tp->p2.y == \old(tp->p2.y);
ensures \result == (\old(tp->p1.x) - \old(tp->p2.x)) * (\old(tp->p1.x) - \old(tp->p2.x)) + (\old(tp->p1.y) - \old(tp->p2.y)) * (\old(tp->p1.y) - \old(tp->p2.y)) ;

*/

int distance_4(struct TwoPoint * tp) 

{
    int dx = (tp->p1.x) - (tp->p2.x);
    int dy = (tp->p1.y) - (tp->p2.y);

    return dx * dx + dy * dy;
}