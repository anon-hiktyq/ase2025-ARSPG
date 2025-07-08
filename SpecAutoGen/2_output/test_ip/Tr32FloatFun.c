
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

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

/*@
With pIp_pA_v pIp_pA pIp_pB_v pIp_pB pIp_pC_v pIp_pC pIp_ui2f_ui08_l pIp_ui2f_ui08_0 pIp_ui2f_ui08_1 pIp_ui2f_ui08_2 pIp_ui2f_ui08_3 pIp_ui2f_flt32 pIp_ui2f_ui32 pIp_f2ui1_ui08_l pIp_f2ui1_ui08_0 pIp_f2ui1_ui08_1 pIp_f2ui1_ui08_2 pIp_f2ui1_ui08_3 pIp_f2ui1_flt32 pIp_f2ui1_ui32 pIp_f2ui2_ui08_l pIp_f2ui2_ui08_0 pIp_f2ui2_ui08_1 pIp_f2ui2_ui08_2 pIp_f2ui2_ui08_3 pIp_f2ui2_flt32 pIp_f2ui2_ui32 pIp_f2ui3_ui08_l pIp_f2ui3_ui08_0 pIp_f2ui3_ui08_1 pIp_f2ui3_ui08_2 pIp_f2ui3_ui08_3 pIp_f2ui3_flt32 pIp_f2ui3_ui32 pIp_ret_v pIp_ret
Require *(pIp->pA) == pIp_pA_v && (pIp->pA) == pIp_pA && *(pIp->pB) == pIp_pB_v && (pIp->pB) == pIp_pB && *(pIp->pC) == pIp_pC_v && (pIp->pC) == pIp_pC && store_int_array(pIp->ui2f.ui08,4, pIp_ui2f_ui08_l) && pIp_ui2f_ui08_l[0] == pIp_ui2f_ui08_0 && pIp_ui2f_ui08_l[1] == pIp_ui2f_ui08_1 && pIp_ui2f_ui08_l[2] == pIp_ui2f_ui08_2 && pIp_ui2f_ui08_l[3] == pIp_ui2f_ui08_3 && pIp->ui2f.flt32 == pIp_ui2f_flt32 && pIp->ui2f.ui32 == pIp_ui2f_ui32 && store_int_array(pIp->f2ui1.ui08,4, pIp_f2ui1_ui08_l) && pIp_f2ui1_ui08_l[0] == pIp_f2ui1_ui08_0 && pIp_f2ui1_ui08_l[1] == pIp_f2ui1_ui08_1 && pIp_f2ui1_ui08_l[2] == pIp_f2ui1_ui08_2 && pIp_f2ui1_ui08_l[3] == pIp_f2ui1_ui08_3 && pIp->f2ui1.flt32 == pIp_f2ui1_flt32 && pIp->f2ui1.ui32 == pIp_f2ui1_ui32 && store_int_array(pIp->f2ui2.ui08,4, pIp_f2ui2_ui08_l) && pIp_f2ui2_ui08_l[0] == pIp_f2ui2_ui08_0 && pIp_f2ui2_ui08_l[1] == pIp_f2ui2_ui08_1 && pIp_f2ui2_ui08_l[2] == pIp_f2ui2_ui08_2 && pIp_f2ui2_ui08_l[3] == pIp_f2ui2_ui08_3 && pIp->f2ui2.flt32 == pIp_f2ui2_flt32 && pIp->f2ui2.ui32 == pIp_f2ui2_ui32 && store_int_array(pIp->f2ui3.ui08,4, pIp_f2ui3_ui08_l) && pIp_f2ui3_ui08_l[0] == pIp_f2ui3_ui08_0 && pIp_f2ui3_ui08_l[1] == pIp_f2ui3_ui08_1 && pIp_f2ui3_ui08_l[2] == pIp_f2ui3_ui08_2 && pIp_f2ui3_ui08_l[3] == pIp_f2ui3_ui08_3 && pIp->f2ui3.flt32 == pIp_f2ui3_flt32 && pIp->f2ui3.ui32 == pIp_f2ui3_ui32 && *(pIp->ret) == pIp_ret_v && (pIp->ret) == pIp_ret
Ensure (pIp_ui2f_ui08_l[0] == pIp_ui2f_ui08_0 && pIp_ui2f_ui08_l[1] == pIp_ui2f_ui08_1 && pIp_ui2f_ui08_l[2] == pIp_ui2f_ui08_2 && pIp_ui2f_ui08_l[3] == pIp_ui2f_ui08_3 && pIp_f2ui1_ui08_l[0] == pIp_f2ui1_ui08_0 && pIp_f2ui1_ui08_l[1] == pIp_f2ui1_ui08_1 && pIp_f2ui1_ui08_l[2] == pIp_f2ui1_ui08_2 && pIp_f2ui1_ui08_l[3] == pIp_f2ui1_ui08_3 && pIp_f2ui2_ui08_l[0] == pIp_f2ui2_ui08_0 && pIp_f2ui2_ui08_l[1] == pIp_f2ui2_ui08_1 && pIp_f2ui2_ui08_l[2] == pIp_f2ui2_ui08_2 && pIp_f2ui2_ui08_l[3] == pIp_f2ui2_ui08_3 && pIp_f2ui3_ui08_l[0] == pIp_f2ui3_ui08_0 && pIp_f2ui3_ui08_l[1] == pIp_f2ui3_ui08_1 && pIp_f2ui3_ui08_l[2] == pIp_f2ui3_ui08_2 && pIp_f2ui3_ui08_l[3] == pIp_f2ui3_ui08_3 && (pIp->pA == pIp_pA) * (*pIp->pA == pIp_ui2f_flt32) * (pIp->pB == pIp_pB) * (*pIp->pB == pIp_ui2f_flt32) * (pIp->pC == pIp_pC) * (*pIp->pC == pIp_ui2f_flt32) * store_int_array(&pIp->ui2f.ui08, 4, pIp_ui2f_ui08_l) * (pIp->ui2f.flt32 == pIp_ui2f_flt32) * (pIp->ui2f.ui32 == (pIp_f2ui1_ui32 & pIp_f2ui2_ui32 | pIp_f2ui1_ui32 & pIp_f2ui3_ui32 | pIp_f2ui2_ui32 & pIp_f2ui3_ui32)) * store_int_array(&pIp->f2ui1.ui08, 4, pIp_f2ui1_ui08_l) * (pIp->f2ui1.flt32 == pIp_pA_v) * (pIp->f2ui1.ui32 == pIp_f2ui1_ui32) * store_int_array(&pIp->f2ui2.ui08, 4, pIp_f2ui2_ui08_l) * (pIp->f2ui2.flt32 == pIp_pB_v) * (pIp->f2ui2.ui32 == pIp_f2ui2_ui32) * store_int_array(&pIp->f2ui3.ui08, 4, pIp_f2ui3_ui08_l) * (pIp->f2ui3.flt32 == pIp_pC_v) * (pIp->f2ui3.ui32 == pIp_f2ui3_ui32) * (pIp->ret == pIp_ret) * (*pIp->ret == pIp_ui2f_flt32))
*/
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