

/*@

ensures (\old(a) > 0 ) ==> ( \result == \old(a) + 1 + b);

ensures (a <= 0 ) ==> ( \result == a + (\old(b) + 1));

*/

int foo3(int a, int b) 
{
    
    if(a> 0) { 
     a = a + 1;
    }else{
     b = b + 1;
    }
    
    return a+ b;
 }