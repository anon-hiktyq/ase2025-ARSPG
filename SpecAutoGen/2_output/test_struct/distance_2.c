
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    struct Point {
    int *x;
    int *y;
};

int distance_2(struct Point* p1, struct Point *p2) 

/*@
With p1_x_v p1_y_v p2_x_v p2_y_v
Require *(p1->x) == p1_x_v && *(p1->y) == p1_y_v && *(p2->x) == p2_x_v && *(p2->y) == p2_y_v
Ensure (__return == (p2_x_v - p1_x_v) * (p2_x_v - p1_x_v) + (p2_y_v - p1_y_v) * (p2_y_v - p1_y_v) && (*p1->x == p1_x_v) * (*p1->y == p1_y_v) * (*p2->x == p2_x_v) * (*p2->y == p2_y_v))
*/
{
    int dx = *(p2->x) - *(p1->x);
    int dy = *(p2->y) - *(p1->y);
    return dx * dx + dy * dy;
}