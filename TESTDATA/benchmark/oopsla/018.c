
/*@
requires flag > 0;
*/
void foo(int flag, int a) {
   int b = 0;
   int j = 0;
 
   for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   /*@ assert falg ==> (j == 100); */
}