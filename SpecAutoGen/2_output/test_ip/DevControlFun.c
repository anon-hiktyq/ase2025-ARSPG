
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __DevControl
{
  int * p1;
  int * p2;
  int * p3;

} DevControl;

void DevControlFun(DevControl *pIp)

/*@
With pIp_p1_v pIp_p1 pIp_p2_v pIp_p2 pIp_p3_v pIp_p3
Require *(pIp->p1) == pIp_p1_v && (pIp->p1) == pIp_p1 && *(pIp->p2) == pIp_p2_v && (pIp->p2) == pIp_p2 && *(pIp->p3) == pIp_p3_v && (pIp->p3) == pIp_p3
Ensure ((pIp->p1 == pIp_p1) * (*pIp->p1 == 60306) * (pIp->p2 == pIp_p2) * (*pIp->p2 == 1) * (pIp->p3 == pIp_p3) * (*pIp->p3 == 252))
*/
{
	*(pIp->p1)= 0xEB92;

	*(pIp->p2)= 0x01;

	*(pIp->p3)= 0xFC;

	return ;
}