
// Define the TripleAbsMax structure based on its usage in the code
typedef struct {
    int fabs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

void TripleAbsMaxFun(TripleAbsMax *pIp)
{
    int threshold =0;

    int i=0;
    
            
            /*@
          logic integer pIp_fabs_l[3];
          logic integer pIp_tmax;
          logic integer pIp_ret_v;
          
          loop invariant store_int_array(&pIp->fabs, 3, pIp_fabs_l);
          loop invariant (0<\at(pIp, Pre)->tmax) ==> (threshold == (i * (i - 1)) / 2);
          loop invariant (0<\at(pIp, Pre)->tmax) ==> (0 <= i <= \at(pIp, Pre)->tmax);
          loop invariant (!(0<\at(pIp, Pre)->tmax)) ==> ((i == 0)&&(threshold == 0)&&(pIp == \at(pIp, Pre))&&(\at(pIp, Pre)->tmax == pIp_tmax)&&(*\at(pIp, Pre)->ret == pIp_ret_v));
          loop invariant pIp == \at(pIp, Pre);
          loop invariant \at(pIp, Pre)->tmax == pIp_tmax;
          loop invariant *\at(pIp, Pre)->ret == pIp_ret_v;
            */
            while(i<pIp->tmax){
        threshold= threshold+i;
        i++;
    }
            

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
