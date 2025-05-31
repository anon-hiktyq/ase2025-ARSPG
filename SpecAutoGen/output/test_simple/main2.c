

/*@

ensures \result >= 10 && (\old(a) < 10 ==> \result == \old(a) || \old(a) < \result && \result <= 10) && (!(\old(a) < 10) ==> \result == \old(a));

*/

int foo2(int a)
{

    /*@
      loop invariant (\at(a, Pre)<10) ==> (((a == \at(a, Pre))) || (\at(a, Pre) < a && a <= 10));
      loop invariant (!(\at(a, Pre)<10)) ==> ((a == \at(a, Pre)));
    */
    while (a<10 ){
        a++;
    }
        
    return a;

}
/*@

ensures \result >= 10 && (5 < 10 ==> \result == 5 || 5 < \result && \result <= 10) && (!(5 < 10) ==> \result == 5);

*/

int main2()
{

   return foo2(5);

}