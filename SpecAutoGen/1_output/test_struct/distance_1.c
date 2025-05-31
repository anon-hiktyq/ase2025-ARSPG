
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    struct Point {
    int x;
    int y;
};

int distance_1(struct Point* p1, struct Point *p2) 
/*@
With p1_x p1_y p2_x p2_y
Require p1->x == p1_x && p1->y == p1_y && p2->x == p2_x && p2->y == p2_y
Ensure Results(__return)
*/{
    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;
    return dx * dx + dy * dy;
}