
typedef struct __TripleAbsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

/*@
    requires \valid(pIp);
    requires \valid(pIp->ret);
    ensures \forall integer i; 0 <= i < 3 ==> 0 <= pIp->fabs[i];
    ensures \exists integer i; 0 <= i < 3 && pIp->tmax == \max(pIp->fabs[0], \max(pIp->fabs[1], pIp->fabs[2]));
    ensures *(pIp->ret) == pIp->tmax || *(pIp->ret) == \old(*(pIp->ret));
*/
void TripleAbsMaxFun(TripleAbsMax *pIp)
{
    int threshold = 0;
    int i = 0;

    /*@
    
    */
    while (i < pIp->tmax) {
        threshold = threshold + i;
        i++;
    }

    int fabsfx1 = pIp->fabs[0];
    int fabsfy2 = pIp->fabs[1];
    int fabsfz3 = pIp->fabs[2];

    if (pIp->fabs[0] < 0) {
        fabsfx1 = -pIp->fabs[0];
    }

    if (pIp->fabs[1] < 0) {
        fabsfy2 = -pIp->fabs[1];
    }

    if (pIp->fabs[2] < 0) {
        fabsfz3 = -pIp->fabs[2];
    }

    if (fabsfx1 > fabsfy2) {
        pIp->tmax = fabsfx1;
    } else {
        pIp->tmax = fabsfy2;
    }

    if (fabsfz3 > pIp->tmax) {
        pIp->tmax = fabsfz3;
    }

    if (pIp->tmax > threshold) {
        *(pIp->ret) = pIp->tmax;
    }
}
