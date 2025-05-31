

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