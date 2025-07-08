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

/*@
 requires \valid(pIp) && \valid(pIp->pA) && \valid(pIp->pB) && \valid(pIp->pC) && \valid(pIp->ui2f.ui08+ (0..4)) && \valid(pIp->f2ui1.ui08+ (0..4)) && \valid(pIp->f2ui2.ui08+ (0..4)) && \valid(pIp->f2ui3.ui08+ (0..4)) && \valid(pIp->ret) ;
 requires \separated(pIp,pIp->pA,pIp->pB,pIp->pC,pIp->ui2f.ui08+(0..4),pIp->f2ui1.ui08+(0..4),pIp->f2ui2.ui08+(0..4),pIp->f2ui3.ui08+(0..4),pIp->ret) ;

ensures pIp->ui2f.ui08[0] == \old(pIp->ui2f.ui08[0]) && pIp->ui2f.ui08[1] == \old(pIp->ui2f.ui08[1]) && pIp->ui2f.ui08[2] == \old(pIp->ui2f.ui08[2]) && pIp->ui2f.ui08[3] == \old(pIp->ui2f.ui08[3]) && pIp->f2ui1.ui08[0] == \old(pIp->f2ui1.ui08[0]) && pIp->f2ui1.ui08[1] == \old(pIp->f2ui1.ui08[1]) && pIp->f2ui1.ui08[2] == \old(pIp->f2ui1.ui08[2]) && pIp->f2ui1.ui08[3] == \old(pIp->f2ui1.ui08[3]) && pIp->f2ui2.ui08[0] == \old(pIp->f2ui2.ui08[0]) && pIp->f2ui2.ui08[1] == \old(pIp->f2ui2.ui08[1]) && pIp->f2ui2.ui08[2] == \old(pIp->f2ui2.ui08[2]) && pIp->f2ui2.ui08[3] == \old(pIp->f2ui2.ui08[3]) && pIp->f2ui3.ui08[0] == \old(pIp->f2ui3.ui08[0]) && pIp->f2ui3.ui08[1] == \old(pIp->f2ui3.ui08[1]) && pIp->f2ui3.ui08[2] == \old(pIp->f2ui3.ui08[2]) && pIp->f2ui3.ui08[3] == \old(pIp->f2ui3.ui08[3]) ==> pIp->pA == \old(pIp->pA)&&*pIp->pA == \old(pIp->ui2f.flt32)&&pIp->pB == \old(pIp->pB)&&*pIp->pB == \old(pIp->ui2f.flt32)&&pIp->pC == \old(pIp->pC)&&*pIp->pC == \old(pIp->ui2f.flt32)&&pIp->ui2f.flt32 == \old(pIp->ui2f.flt32)&&pIp->ui2f.ui32 == (\old(pIp->f2ui1.ui32) & \old(pIp->f2ui2.ui32) | \old(pIp->f2ui1.ui32) & \old(pIp->f2ui3.ui32) | \old(pIp->f2ui2.ui32) & \old(pIp->f2ui3.ui32))&&pIp->f2ui1.flt32 == \old(*pIp->pA)&&pIp->f2ui1.ui32 == \old(pIp->f2ui1.ui32)&&pIp->f2ui2.flt32 == \old(*pIp->pB)&&pIp->f2ui2.ui32 == \old(pIp->f2ui2.ui32)&&pIp->f2ui3.flt32 == \old(*pIp->pC)&&pIp->f2ui3.ui32 == \old(pIp->f2ui3.ui32)&&pIp->ret == \old(pIp->ret)&&*pIp->ret == \old(pIp->ui2f.flt32);

*/

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