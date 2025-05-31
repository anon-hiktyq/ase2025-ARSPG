void ModPNHPFun(ModPNHP *pIp)
{

    int period;


    period = 2 * pIp -> halfperiod;

    pIp -> npp2 = pIp -> x - period ;

    *(pIp -> ret) = pIp -> npp2;
}