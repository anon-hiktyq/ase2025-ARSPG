
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __MatrixTran
{

	const int*	mat;
	int			nrow;
	int			ncol;
	int*		tran;
	
} MatrixTran;

void MatrixTranFun(MatrixTran *pIp)

/*@
With pIp_mat_v pIp_mat pIp_nrow pIp_ncol pIp_tran_v pIp_tran
Require *(pIp->mat) == pIp_mat_v && (pIp->mat) == pIp_mat && pIp->nrow == pIp_nrow && pIp->ncol == pIp_ncol && *(pIp->tran) == pIp_tran_v && (pIp->tran) == pIp_tran
Ensure emp
*/{

    int i = 0;
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (; i<pIp -> nrow ; i++ )
    {
        int j = 0;
        
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (; j<pIp -> ncol ; j++ )
        {
            *(pIp -> tran + j * pIp -> nrow + i) = *(pIp -> mat + i * pIp -> ncol + j) ;
        }
    }

    return ;
}