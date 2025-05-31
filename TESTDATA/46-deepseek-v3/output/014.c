
int unknown();


/*@ requires m > 0;*/
void foo(int m) {
  int a = 0;
  
  int j = 1;
  
                
                /*@
          loop invariant (1 <= \at(m, Pre)) ==> (((j == 1)&&(a == 0)&&(m == \at(m, Pre))) || (a >= -(j-1) && a <= (j-1)));
          loop invariant (1 <= \at(m, Pre)) ==> (((j == 1)&&(a == 0)&&(m == \at(m, Pre))) || (1 <= j && j <= m+1));
          loop invariant (!(1 <= \at(m, Pre))) ==> ((j == 1)&&(a == 0)&&(m == \at(m, Pre)));
          loop invariant m == \at(m, Pre);
                */
                for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
                
  /*@ assert a>= -m && a <= m;*/
}
