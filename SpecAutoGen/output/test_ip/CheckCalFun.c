
typedef struct __CheckCal
{
	int		len;
	int*	pkv;
	int     chksum;
	
} CheckCal;

/*@
    requires \valid(pIp);
    requires \valid(pIp->pkv + (0 .. pIp->len-1));
    ensures pIp->chksum == \sum(0, pIp->len-1, \lambda integer i; \at(pIp->pkv[i], Pre));
*/
void CheckCalFun(CheckCal *pIp)
{
    int i;
    int chksum = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant pIp->pkv == \at(pIp->pkv, Pre);
      loop invariant pIp->len == \at(pIp->len, Pre);
      loop invariant pIp == \at(pIp, Pre);
      loop invariant 0 <= i <= pIp->len;
      loop invariant chksum == \sum(0, i-1, \lambda integer j; \at(pIp->pkv[j], Pre));
      loop assigns i, chksum;
      loop variant pIp->len - i;
    */
    for(i=0; i<pIp->len; i++)
    {
        chksum = chksum + pIp->pkv[i];
    }

    pIp->chksum = chksum;
    return;
}
