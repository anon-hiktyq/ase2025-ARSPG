
int unknown();

void foo(int flag)
{

    int x = 0;
    int y = 0;
    int j = 0;
    int i = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= i && x == i && y == j);
      loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= i && x == i && y == j);
      loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= i && x == i && y == j);
      loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= i && x == i && y == j);
      loop invariant flag == \at(flag, Pre);
    */
    while (unknown())
    {
        x++;
        y++;
        i += x;
        j += y;
        if (flag){
            j += 1;
        }
    }

    /*@ assert j >= i; */
}
