typedef struct __TripleFabsMax
{

 int fabs[3];
 int tmax;
 int* ret;

} TripleFabsMax;

/*@

ensures pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) ==> pIp->tmax == pIp->fabs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[1];

ensures pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) ==> pIp->tmax == pIp->fabs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[0];

ensures pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

ensures pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) ==> pIp->tmax == pIp->fabs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->fabs[2];

*/

void main(TripleFabsMax *pIp)

{

    int fabsfx1 = pIp->fabs[0];
    int fabsfy2 = pIp->fabs[1];
    int fabsfz3 = pIp->fabs[2];


    if (fabsfx1 > fabsfy2)
    {
        pIp -> tmax = fabsfx1 ;
    }
    else
    {
        pIp -> tmax = fabsfy2 ;
    }

    if (fabsfz3 > pIp -> tmax)
    {
        pIp -> tmax = fabsfz3 ;
    }

    *(pIp -> ret) = pIp->tmax ;
}