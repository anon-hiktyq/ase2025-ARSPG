void TripleFabsMaxFun_(TripleFabsMax *pIp)
{

    int threshold = getThreshold(3);

    int fabsfx1 = pIp -> fabs[0];
    int fabsfy2 = pIp -> fabs[1];
    int fabsfz3 = pIp -> fabs[2];

     if (pIp -> fabs[0] < 0)
    {
        fabsfx1 = -pIp -> fx1;
    }

    if (pIp -> fabs[1] < 0)
    {
        fabsfy2 = -pIp -> fy2;
    }

    if (pIp -> fabs[2] < 0)
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


    if (pIp->tmax > threshold){
        *(pIp -> ret) = pIp->tmax;
    }else{
        *(pIp -> ret) = 0;
    }
}