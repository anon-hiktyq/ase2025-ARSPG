
typedef union TAG_DATA_TYPE_CONVERT
{
      
    int ui08[4];				 	
    int flt32;                   	
    int ui32;                    	
                                     	
} UDTConvert;


typedef struct __Tr32Float
{
	int*			pA;
	int*			pB;
	int*			pC;
	
	UDTConvert		ui2f;
    UDTConvert     f2ui1 ;
    UDTConvert     f2ui2 ;
    UDTConvert     f2ui3 ;
	int*			ret;
	
} Tr32Float;

void Tr32FloatFun(Tr32Float *pIp)
{

  
    int uitemp1 ;
    int uitemp2 ;
    int uitemp3 ;


    pIp->f2ui1.flt32 = *(pIp -> pA) ;
    pIp->f2ui2.flt32 = *(pIp -> pB) ;
    pIp->f2ui3.flt32 = *(pIp -> pC) ;

    uitemp1 = pIp->f2ui1.ui32 & pIp->f2ui2.ui32 ;
    uitemp2 = pIp->f2ui1.ui32 & pIp->f2ui3.ui32 ;
    uitemp3 = pIp->f2ui2.ui32 & pIp->f2ui3.ui32 ;
    pIp -> ui2f.ui32 = uitemp1 | uitemp2 | uitemp3 ;

    *(pIp -> pA) = pIp -> ui2f.flt32 ;
    *(pIp -> pB) = pIp -> ui2f.flt32 ;
    *(pIp -> pC) = pIp -> ui2f.flt32 ;

    *(pIp -> ret) = pIp -> ui2f.flt32 ;
}