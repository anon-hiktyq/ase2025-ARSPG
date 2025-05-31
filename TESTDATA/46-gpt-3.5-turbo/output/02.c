
void foo()
{
    int i = 1;
    int j = 0;
    int z = i - j;
    int x = 0;
    int y = 0;
    int w = 0;

    /*@      loop invariant (x == y + (z - 1) / 2);
    */
    while(unknown()) 
    {
        z += x + y + w;
        y++;
        if (z % 2 == 1) 
            x++;
        w += 2; 
    }

    /*@ assert x == y; */
}
