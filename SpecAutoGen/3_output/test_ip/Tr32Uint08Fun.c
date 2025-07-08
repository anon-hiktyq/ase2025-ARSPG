typedef struct __Tr32Uint08
{

	int *			pC;
	int *			pB;
	int *			pA;
	int		  uiresult;
	int *		   ret;

} Tr32Uint08;

void Tr32Uint08Fun(Tr32Uint08 *pIp)
{

    int uitemp1 ;
    int uitemp2 ;
    int uitemp3 ;
   

    if ((*(pIp -> pA) == *(pIp -> pB)) && (*(pIp -> pA) == *(pIp -> pC)))
    {
        pIp -> uiresult = *(pIp -> pA) ;
    }
    else
    {
        uitemp1 = *(pIp -> pA) & *(pIp -> pB) ;
        uitemp2 = *(pIp -> pA) & *(pIp -> pC) ;
        uitemp3 = *(pIp -> pB) & *(pIp -> pC) ;
        pIp -> uiresult = uitemp1 | uitemp2 | uitemp3 ;

        *(pIp -> pA) = pIp -> uiresult ;
        *(pIp -> pB) = pIp -> uiresult ;
        *(pIp -> pC) = pIp -> uiresult ;
    }

    *(pIp -> ret) = pIp -> uiresult ;
}