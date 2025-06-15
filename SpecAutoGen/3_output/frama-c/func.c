

/*@

ensures a == 0 ==> \result == 10 / (0 + 0);

ensures a != 0 ==> \result == 10 / (5 + 5);

*/

int func(int a) 
{
    int x, y;
    int sum, res;
    if (a == 0){
        x = 0; y = 0;
    }
    else {
        x = 5; y = 5;
    }
    sum = x + y; 
    res = 10/sum; 
    return res;
}