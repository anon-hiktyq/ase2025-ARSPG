
    
int unknown();

/*@ requires m > 0;*/
/*@ assigns a; */
/*@ loop invariant (\at(m, Pre) > 0) ==> ((1 <= \at(m, Pre)) ==> (((j == 1)&&(a == 0)&&(m == \at(m, Pre))) || (0 <= a && a <= j))) ;
    loop invariant (\at(m, Pre) > 0) ==> ((1 <= \at(m, Pre)) ==> (((j == 1)&&(a == 0)&&(m == \at(m, Pre))) || (j <= m))) ;
    loop invariant (\at(m, Pre) > 0) ==> ((!(1 <= \at(m, Pre))) ==> ((j == 1)&&(a == 0)&&(m == \at(m, Pre))));
    loop invariant (\at(m, Pre) > 0) ==> (m == \at(m, Pre));
*/
void foo() {
  int a = 0;
  int j;
  int m;

  for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
            
  /* assert a>= -m && a <= m;*/
}
