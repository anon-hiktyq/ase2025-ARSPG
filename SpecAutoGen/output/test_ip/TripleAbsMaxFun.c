typedef struct __TripleAbsMax
{
    int abs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

/*@
 requires \valid(pIp) && \valid(pIp->abs+ (0..3)) && \valid(pIp->ret) ;
 requires \separated(pIp,pIp->abs+(0..3),pIp->ret) ;

ensures -pIp->abs[2] <= pIp->abs[1] && pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[1];

ensures -pIp->abs[2] <= pIp->abs[1] && -pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[1];

ensures -pIp->abs[2] <= -pIp->abs[1] && -pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[1];

ensures -pIp->abs[2] <= -pIp->abs[1] && pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[1];

ensures pIp->abs[2] <= -pIp->abs[1] && pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[1];

ensures pIp->abs[2] <= -pIp->abs[1] && -pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[1];

ensures pIp->abs[2] <= pIp->abs[1] && -pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[1];

ensures pIp->abs[2] <= pIp->abs[1] && pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[1]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[1];

ensures -pIp->abs[2] <= pIp->abs[0] && pIp->abs[0] > pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[0];

ensures -pIp->abs[2] <= -pIp->abs[0] && -pIp->abs[0] > pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[0];

ensures -pIp->abs[2] <= -pIp->abs[0] && -pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[0];

ensures -pIp->abs[2] <= pIp->abs[0] && pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[0];

ensures pIp->abs[2] <= pIp->abs[0] && pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[0];

ensures pIp->abs[2] <= -pIp->abs[0] && -pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[0];

ensures pIp->abs[2] <= -pIp->abs[0] && -pIp->abs[0] > pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[0];

ensures pIp->abs[2] <= pIp->abs[0] && pIp->abs[0] > pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[0]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[0];

ensures pIp->abs[2] > pIp->abs[0] && pIp->abs[0] > pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > -pIp->abs[0] && -pIp->abs[0] > pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > -pIp->abs[0] && -pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > pIp->abs[0] && pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures -pIp->abs[2] > pIp->abs[0] && pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > -pIp->abs[0] && -pIp->abs[0] > -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > -pIp->abs[0] && -pIp->abs[0] > pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > pIp->abs[0] && pIp->abs[0] > pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures pIp->abs[2] > pIp->abs[1] && pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > pIp->abs[1] && -pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > -pIp->abs[1] && -pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures pIp->abs[2] > -pIp->abs[1] && pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] >= 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == pIp->abs[2];

ensures -pIp->abs[2] > -pIp->abs[1] && pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > -pIp->abs[1] && -pIp->abs[0] <= -pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] < 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > pIp->abs[1] && -pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] < 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

ensures -pIp->abs[2] > pIp->abs[1] && pIp->abs[0] <= pIp->abs[1] && pIp->abs[2] < 0 && pIp->abs[1] >= 0 && pIp->abs[0] >= 0 && pIp->abs[0] == \old(pIp->abs[0]) && pIp->abs[1] == \old(pIp->abs[1]) && pIp->abs[2] == \old(pIp->abs[2]) ==> pIp->tmax == -pIp->abs[2]&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -pIp->abs[2];

*/

void TripleAbsMaxFun(TripleAbsMax *pIp)

{
    
    int absfx1 = pIp->abs[0];
    int absfy2 = pIp->abs[1];
    int absfz3 = pIp->abs[2];

    if (pIp->abs[0] < 0)
    {
        absfx1 = -pIp->abs[0];
    }

    if (pIp->abs[1] < 0)
    {
        absfy2 = -pIp->abs[1];
    }

    if (pIp->abs[2] < 0)
    {
        absfz3 = -pIp->abs[2];
    }

    if (absfx1 > absfy2)
    {
        pIp->tmax = absfx1;
    }
    else
    {
        pIp->tmax = absfy2;
    }

    if (absfz3 > pIp->tmax)
    {
        pIp->tmax = absfz3;
    }

    *(pIp->ret) = pIp->tmax;
    
}