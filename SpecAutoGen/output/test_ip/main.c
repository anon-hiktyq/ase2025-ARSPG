typedef struct __TripleAbsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

/*@

ensures \exists int i_64;  i_64 > n && (0 <= n ==> 0 <= i_64 && i_64 <= n + 1) ==> (0 <= n ==> \result == i_64 * (i_64 - 1) / 2);

*/

int getThreshold(int n)
{
    int i=0;
    int sum =0;
            
    /*@
          loop invariant (0 <= \at(n, Pre)) ==> (0 <= i <= n+1) ;
          loop invariant (0 <= \at(n, Pre)) ==> (sum == (i*(i-1))/2) ;
          loop invariant n == \at(n, Pre);
    */
    while(i <= n){
        sum += i;
        i++;
    }
                   
    return sum;
}
/*@

ensures \exists int retval_91, i_64_90; (pIp->fabs[1] > retval_91 && -pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] > retval_91 && -pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] > retval_91 && -pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] > retval_91 && -pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] > retval_91 && pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] > retval_91 && pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] > retval_91 && pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] > retval_91 && pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[1];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] > retval_91 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] > retval_91 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] > retval_91 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] > retval_91 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] > retval_91 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] > retval_91 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] > retval_91 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] > retval_91 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[0];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] > retval_91 && pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] > retval_91 && -pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->fabs[2];

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[2] <= retval_91 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[2] <= retval_91 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] <= retval_91 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] <= retval_91 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] <= retval_91 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] <= retval_91 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] <= retval_91 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] <= retval_91 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[0] <= retval_91 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[0] <= retval_91 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] <= retval_91 && pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] <= retval_91 && pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] <= retval_91 && pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] <= retval_91 && pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] <= retval_91 && -pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (-pIp->fabs[1] <= retval_91 && -pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == -pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] <= retval_91 && -pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

ensures \exists int retval_91, i_64_90;  (pIp->fabs[1] <= retval_91 && -pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0 && i_64_90 > 3 && (0 <= 3 ==> 0 <= i_64_90 && i_64_90 <= 3 + 1) && (0 <= 3 ==> retval_91 == i_64_90 * (i_64_90 - 1) / 2) ) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(*pIp->ret);

*/

void main(TripleAbsMax *pIp)

{
    
    int threshold = getThreshold(3);

    int fabsfx1 = pIp->fabs[0];
    int fabsfy2 = pIp->fabs[1];
    int fabsfz3 = pIp->fabs[2];

    if (pIp->fabs[0] < 0)
    {
        fabsfx1 = -pIp->fabs[0];
    }

    if (pIp->fabs[1] < 0)
    {
        fabsfy2 = -pIp->fabs[1];
    }

    if (pIp->fabs[2] < 0)
    {
        fabsfz3 = -pIp->fabs[2];
    }

    if (fabsfx1 > fabsfy2)
    {
        pIp->tmax = fabsfx1;
    }
    else
    {
        pIp->tmax = fabsfy2;
    }

    if (fabsfz3 > pIp->tmax)
    {
        pIp->tmax = fabsfz3;
    }


    if (pIp->tmax > threshold)
    {
        *(pIp->ret) = pIp->tmax;
    }
}