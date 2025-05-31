
/*@
requires flag > 0;
*/
void foo(int flag, int a) {
   int b = 0;
   int j = 0;
 
   
            
            /*@
          loop invariant  (\at(flag, Pre) > 0) ==> (((j == 0)&&(b == 0)&&(a == \at(a, Pre))&&(flag == \at(flag, Pre))) || (0 <= b && b <= 100)) ;
          loop invariant  (\at(flag, Pre) > 0) ==> (((j == 0)&&(b == 0)&&(a == \at(a, Pre))&&(flag == \at(flag, Pre))) || (j == b)) ;
          loop invariant (\at(flag, Pre) > 0) ==> (a == \at(a, Pre));
          loop invariant (\at(flag, Pre) > 0) ==> (flag == \at(flag, Pre));
            */
            for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }
            

   /*@ assert flag ==> (j == 100); */
}
