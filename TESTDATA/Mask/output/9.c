
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

/*@ 
    loop invariant x >= 0 && x <= 2 + 2 * (x / 2) ;
    loop invariant y >= 0 && y <= 2 + 2 * (y / 2) ;
*/
while (unknown()) {
    x = x + 2;
    y = y + 2;
}
 /*@ assert (x == 4) ==> (y != 0);  */

}
112