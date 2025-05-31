
int unknown();

void foo()
{
    int i = 1;
    int j = 0;
    int z = i - j;
    int x = 0;
    int y = 0;
    int w = 0;

    /* >>> LOOP INVARIANT TO FILL <<< 
    >>> PRECONDITION OF THE LOOP : (w == 0) * (y == 0) * (x == 0) * (z == 1 - 0) * (j == 0) * (i == 1) <<< */

    /*@
        loop invariant 0 <= x <= y; 
        loop invariant w == 2 * y;
    */
    while(unknown()) 
    {
        z += x + y + w;
        y++;
        if (z % 2 == 1) 
            x++;
        w += 2; 
    }

    /*@ assert x <= y; */
}
