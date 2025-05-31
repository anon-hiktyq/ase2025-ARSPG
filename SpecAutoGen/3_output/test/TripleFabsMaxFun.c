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