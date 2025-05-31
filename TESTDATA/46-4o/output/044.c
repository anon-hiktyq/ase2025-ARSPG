
void foo(int k, int flag , int __BLAST_NONDET)
{
  int i=0;
  int j=0;
  int n;
 
  if (flag == 1){
     n=1;
  } else {
     n=2;
  }

  i=0;
  
            /*@
          loop invariant  (\at(flag, Pre) == 1) ==> ((0 <= \at(k, Pre)) ==> (((n == 1)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))) || (j == i * n))) ;
          loop invariant  (\at(flag, Pre) == 1) ==> ((0 <= \at(k, Pre)) ==> (((n == 1)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))) || (j == i * n))) ;
          loop invariant (\at(flag, Pre) == 1) ==> ((!(0 <= \at(k, Pre))) ==> ((n == 1)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))));
          loop invariant (\at(flag, Pre) == 1) ==> (n == 1);
          loop invariant (\at(flag, Pre) == 1) ==> (__BLAST_NONDET == \at(__BLAST_NONDET, Pre));
          loop invariant (\at(flag, Pre) == 1) ==> (flag == \at(flag, Pre));
          loop invariant (\at(flag, Pre) == 1) ==> (k == \at(k, Pre));
          loop invariant  (\at(flag, Pre) != 1) ==> ((0 <= \at(k, Pre)) ==> (((n == 2)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))) || (j == i * n))) ;
          loop invariant  (\at(flag, Pre) != 1) ==> ((0 <= \at(k, Pre)) ==> (((n == 2)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))) || (j == i * n))) ;
          loop invariant (\at(flag, Pre) != 1) ==> ((!(0 <= \at(k, Pre))) ==> ((n == 2)&&(j == 0)&&(i == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(flag == \at(flag, Pre))&&(k == \at(k, Pre))));
          loop invariant (\at(flag, Pre) != 1) ==> (n == 2);
          loop invariant (\at(flag, Pre) != 1) ==> (__BLAST_NONDET == \at(__BLAST_NONDET, Pre));
          loop invariant (\at(flag, Pre) != 1) ==> (flag == \at(flag, Pre));
          loop invariant (\at(flag, Pre) != 1) ==> (k == \at(k, Pre));
            */
            while ( i <= k) {
    i++;
    j = j + n;
  }
            
  /*@ assert (flag == 1) ==> (j == i);*/
}
