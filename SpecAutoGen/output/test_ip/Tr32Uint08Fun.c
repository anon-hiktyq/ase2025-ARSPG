typedef struct __Tr32Uint08
{

	int *			pC;
	int *			pB;
	int *			pA;
	int		  uiresult;
	int *		   ret;

} Tr32Uint08;

/*@
 requires \valid(pIp) && \valid(pIp->pC) && \valid(pIp->pB) && \valid(pIp->pA) && \valid(pIp->ret) ;
 requires \separated(pIp,pIp->pC,pIp->pB,pIp->pA,pIp->ret) ;

ensures \old(*pIp->pA) != \old(*pIp->pC) && \old(*pIp->pA) == \old(*pIp->pB) ==> pIp->pC == \old(pIp->pC)&&*\old(pIp->pC) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->pB == \old(pIp->pB)&&*\old(pIp->pB) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->pA == \old(pIp->pA)&&*\old(pIp->pA) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->uiresult == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC));

ensures \old(*pIp->pA) != \old(*pIp->pB) ==> pIp->pC == \old(pIp->pC)&&*\old(pIp->pC) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->pB == \old(pIp->pB)&&*\old(pIp->pB) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->pA == \old(pIp->pA)&&*\old(pIp->pA) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->uiresult == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC))&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == (\old(*pIp->pA) & \old(*pIp->pB) | \old(*pIp->pA) & \old(*pIp->pC) | \old(*pIp->pB) & \old(*pIp->pC));

ensures \old(*pIp->pA) == \old(*pIp->pC) && \old(*pIp->pA) == \old(*pIp->pB) ==> pIp->pC == \old(pIp->pC)&&*pIp->pC == \old(*pIp->pC)&&pIp->pB == \old(pIp->pB)&&*pIp->pB == \old(*pIp->pB)&&pIp->pA == \old(pIp->pA)&&*pIp->pA == \old(*pIp->pA)&&pIp->uiresult == \old(*pIp->pA)&&pIp->ret == \old(pIp->ret)&&*pIp->ret == \old(*pIp->pA);

*/

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