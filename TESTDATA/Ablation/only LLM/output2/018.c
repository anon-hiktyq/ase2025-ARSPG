
/*@
requires flag > 0;
*/
void foo(int flag, int a) {
   int b = 0;
   int j = 0;
 
   /*@
   loop invariant 0 <= b <= 100;
   loop invariant flag ==> (j == b);
   loop assigns b, j;
   loop variant 100 - b;
   */
   for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   /*@ assert flag ==> (j == 100); */
}
