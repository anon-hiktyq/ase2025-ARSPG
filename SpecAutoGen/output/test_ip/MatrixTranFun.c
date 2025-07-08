
typedef struct __MatrixTran
{
	const int*	mat;
	int			nrow;
	int			ncol;
	int*		tran;
	
} MatrixTran;

/*@
  requires \valid(pIp);
  requires \valid(pIp->mat + (0 .. pIp->nrow * pIp->ncol - 1));
  requires \valid(pIp->tran + (0 .. pIp->nrow * pIp->ncol - 1));
  requires pIp->nrow > 0;
  requires pIp->ncol > 0;
  ensures \forall integer i, j; 
          0 <= i < pIp->nrow && 0 <= j < pIp->ncol ==> 
          pIp->tran[j * pIp->nrow + i] == pIp->mat[i * pIp->ncol + j];
*/
void MatrixTranFun(MatrixTran *pIp)
{
    int i = 0;

    /*@
      loop invariant 0 <= i <= pIp->nrow;
      loop invariant \valid(pIp);
      loop invariant \valid(pIp->mat + (0 .. pIp->nrow * pIp->ncol - 1));
      loop invariant \valid(pIp->tran + (0 .. pIp->nrow * pIp->ncol - 1));
      loop invariant \forall integer k, l; 
                    0 <= k < i && 0 <= l < pIp->ncol ==> 
                    pIp->tran[l * pIp->nrow + k] == pIp->mat[k * pIp->ncol + l];
      loop assigns i, *(pIp->tran + (0 .. pIp->nrow * pIp->ncol - 1));
      loop variant pIp->nrow - i;
    */
    for (; i < pIp->nrow; i++)
    {
        int j = 0;

        /*@
          loop invariant 0 <= j <= pIp->ncol;
          loop invariant \valid(pIp);
          loop invariant \valid(pIp->mat + (0 .. pIp->nrow * pIp->ncol - 1));
          loop invariant \valid(pIp->tran + (0 .. pIp->nrow * pIp->ncol - 1));
          loop invariant \forall integer l; 
                        0 <= l < j ==> 
                        pIp->tran[l * pIp->nrow + i] == pIp->mat[i * pIp->ncol + l];
          loop assigns j, *(pIp->tran + (0 .. pIp->nrow * pIp->ncol - 1));
          loop variant pIp->ncol - j;
        */
        for (; j < pIp->ncol; j++)
        {
            *(pIp->tran + j * pIp->nrow + i) = *(pIp->mat + i * pIp->ncol + j);
        }
    }

    return;
}
