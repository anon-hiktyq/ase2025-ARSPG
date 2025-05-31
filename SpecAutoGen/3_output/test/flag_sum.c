
void flag_sum(int flag,int * sum){

    int i = 0;

    *sum = flag;
    
    
            
            /*@
          loop invariant (0 < n) ==> (*sum == \at(flag, Pre) + (i*(i-1))/2) ;
          loop invariant (0 < n) ==> (0 <= i <= n) ;
          loop invariant (!(0 < n)) ==> ((i == 0)&&(sum == \at(sum, Pre))&&(flag == \at(flag, Pre))&&(*sum@pre == \at(flag, Pre)));
          loop invariant flag == \at(flag, Pre);
          loop invariant *sum@pre == \at(flag, Pre);
            */
            while (i < n) {
        *sum += i;
        i++;
    }
            
    

    


}
