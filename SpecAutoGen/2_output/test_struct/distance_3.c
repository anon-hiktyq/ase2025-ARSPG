
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

struct Point {
    int x;
    int y;
};
struct TwoPoint{    
    struct Point *p1;
    struct Point *p2;

};

int distance_3(struct TwoPoint * tp) 

/*@
With tp_p1_x tp_p1_y tp_p2_x tp_p2_y
Require tp->p1->x == tp_p1_x && tp->p1->y == tp_p1_y && tp->p2->x == tp_p2_x && tp->p2->y == tp_p2_y
Ensure (__return == (tp_p1_x - tp_p2_x) * (tp_p1_x - tp_p2_x) + (tp_p1_y - tp_p2_y) * (tp_p1_y - tp_p2_y) && (tp->p1->x == tp_p1_x) * (tp->p1->y == tp_p1_y) * (tp->p2->x == tp_p2_x) * (tp->p2->y == tp_p2_y))
*/
{
    int dx = (tp->p1->x) - (tp->p2->x);
    int dy = (tp->p1->y) - (tp->p2->y);

    return dx * dx + dy * dy;
}