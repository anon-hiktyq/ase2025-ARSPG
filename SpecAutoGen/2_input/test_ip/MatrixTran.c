typedef struct __MatrixTran
{

	const int*	mat;
	int			nrow;
	int			ncol;
	int*		tran;
	
} MatrixTran;


void MatrixTranFun(MatrixTran *pIp)
{

    int i = 0;
   
    for (; i<pIp -> nrow ; i++ )
    {
        int j = 0;
        
        for (; j<pIp -> ncol ; j++ )
        {
            *(pIp -> tran + j * pIp -> nrow + i) = *(pIp -> mat + i * pIp -> ncol + j) ;
        }
    }

    return ;
}