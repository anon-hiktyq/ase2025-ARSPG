
int unknown();

void foo(int flag)
{
    int x = 0;
    int y = 0;
    int j = 0;
    int i = 0;

    /*@ 
      loop invariant x == y;
      loop invariant i == x * (x + 1) / 2;
      loop invariant j >= i;
      loop invariant j <= i + x;
      loop assigns x, y, i, j;
      loop variant 0;
    */
    while(unknown())
    {
        x++;
        y++;
        i += x;
        j += y;
        if (flag) {
            j += 1;
        }
    } 
    /*@ assert j >= i; */
}
