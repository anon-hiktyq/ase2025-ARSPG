
int unknown();

void foo(int flag) {
   int j = 2; 
   int k = 0;

   
   
            
            /*@
          loop invariant  ((k == 0)&&(j == 2)&&(flag == \at(flag, Pre))) || (!flag ==> j == 2 + 2 * k) ;
          loop invariant  ((k == 0)&&(j == 2)&&(flag == \at(flag, Pre))) || (flag ==> k == 0) ;
          loop invariant flag == \at(flag, Pre);
            */
            while(unknown()){ 
     if (flag)
       j = j + 4;
     else {
       j = j + 2;
       k = k + 1;
     }
   }
            
   /*@ assert (k!= 0 )==> (j == 2 * k + 2 ); */
}
