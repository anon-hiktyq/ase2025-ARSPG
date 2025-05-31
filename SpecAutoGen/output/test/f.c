

/*@

ensures *\old(b) == \old(*\old(b)) + 1;
ensures \result == \old(*\old(b)) + 1;

*/

int f(int * b)
{
    
    *b = *b + 1;
    return *b;
  
}