
typedef struct __CheckCal
{
    int     len;
    int*    pkv;
    int     chksum;
    
} CheckCal;

void CheckCalFun(CheckCal *pIp)
{
    int i;
    int chksum = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant pIp->pkv == \at(pIp->pkv, Pre);
      loop invariant pIp->len == \at(pIp->len, Pre);
      loop invariant pIp == \at(pIp, Pre);
    */
    for(i=0; i<pIp->len; i++)
    {
        chksum = chksum + pIp->pkv[i];
    }

    return;
}
