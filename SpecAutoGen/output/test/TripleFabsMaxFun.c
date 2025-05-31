typedef struct __TripleFabsMax
{


 int fx1;
 int fy2;
 int fz3;

 int tmax;
 int* ret;

} TripleFabsMax;

/*@

ensures -\old(pIp->fz3) <= \old(pIp->fy2) && \old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fy2)&&*pIp->ret == \old(pIp->fy2);

ensures -\old(pIp->fz3) <= \old(pIp->fy2) && -\old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fy2)&&*pIp->ret == \old(pIp->fy2);

ensures -\old(pIp->fz3) <= -\old(pIp->fy2) && -\old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fy2)&&*pIp->ret == -\old(pIp->fy2);

ensures -\old(pIp->fz3) <= -\old(pIp->fy2) && \old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fy2)&&*pIp->ret == -\old(pIp->fy2);

ensures \old(pIp->fz3) <= -\old(pIp->fy2) && \old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fy2)&&*pIp->ret == -\old(pIp->fy2);

ensures \old(pIp->fz3) <= -\old(pIp->fy2) && -\old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fy2)&&*pIp->ret == -\old(pIp->fy2);

ensures \old(pIp->fz3) <= \old(pIp->fy2) && -\old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fy2)&&*pIp->ret == \old(pIp->fy2);

ensures \old(pIp->fz3) <= \old(pIp->fy2) && \old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fy2)&&*pIp->ret == \old(pIp->fy2);

ensures -\old(pIp->fz3) <= \old(pIp->fx1) && \old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fx1)&&*pIp->ret == \old(pIp->fx1);

ensures -\old(pIp->fz3) <= -\old(pIp->fx1) && -\old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fx1)&&*pIp->ret == -\old(pIp->fx1);

ensures -\old(pIp->fz3) <= -\old(pIp->fx1) && -\old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fx1)&&*pIp->ret == -\old(pIp->fx1);

ensures -\old(pIp->fz3) <= \old(pIp->fx1) && \old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fx1)&&*pIp->ret == \old(pIp->fx1);

ensures \old(pIp->fz3) <= \old(pIp->fx1) && \old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fx1)&&*pIp->ret == \old(pIp->fx1);

ensures \old(pIp->fz3) <= -\old(pIp->fx1) && -\old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fx1)&&*pIp->ret == -\old(pIp->fx1);

ensures \old(pIp->fz3) <= -\old(pIp->fx1) && -\old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fx1)&&*pIp->ret == -\old(pIp->fx1);

ensures \old(pIp->fz3) <= \old(pIp->fx1) && \old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fx1)&&*pIp->ret == \old(pIp->fx1);

ensures \old(pIp->fz3) > \old(pIp->fx1) && \old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > -\old(pIp->fx1) && -\old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > -\old(pIp->fx1) && -\old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > \old(pIp->fx1) && \old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures -\old(pIp->fz3) > \old(pIp->fx1) && \old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > -\old(pIp->fx1) && -\old(pIp->fx1) > -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > -\old(pIp->fx1) && -\old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > \old(pIp->fx1) && \old(pIp->fx1) > \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures \old(pIp->fz3) > \old(pIp->fy2) && \old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > \old(pIp->fy2) && -\old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > -\old(pIp->fy2) && -\old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures \old(pIp->fz3) > -\old(pIp->fy2) && \old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) >= 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == \old(pIp->fz3)&&*pIp->ret == \old(pIp->fz3);

ensures -\old(pIp->fz3) > -\old(pIp->fy2) && \old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > -\old(pIp->fy2) && -\old(pIp->fx1) <= -\old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) < 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > \old(pIp->fy2) && -\old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) < 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

ensures -\old(pIp->fz3) > \old(pIp->fy2) && \old(pIp->fx1) <= \old(pIp->fy2) && \old(pIp->fz3) < 0 && \old(pIp->fy2) >= 0 && \old(pIp->fx1) >= 0 ==> pIp->fx1 == \old(pIp->fx1)&&pIp->fy2 == \old(pIp->fy2)&&pIp->fz3 == \old(pIp->fz3)&&pIp->tmax == -\old(pIp->fz3)&&*pIp->ret == -\old(pIp->fz3);

*/

void TripleFabsMaxFun(TripleFabsMax *pIp)

{

    int fabsfx1 = pIp -> fx1;
    int fabsfy2 = pIp -> fy2;
    int fabsfz3 = pIp -> fz3;


    if (pIp -> fx1 < 0)
    {
        fabsfx1 = -pIp -> fx1;
    }

    if (pIp -> fy2 < 0)
    {
        fabsfy2 = -pIp -> fy2;
    }

    if (pIp -> fz3 < 0)
    {
        fabsfz3 = -pIp -> fz3;
    }

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