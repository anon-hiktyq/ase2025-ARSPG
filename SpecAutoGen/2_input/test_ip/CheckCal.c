typedef struct __CheckCal
{

	int		len;
	int*	pkv;
	int     chksum;
	
} CheckCal;


void CheckCalFun(CheckCal *pIp)
{

	int i;
	int chksum = 0;

	for(i=0; i<pIp -> len; i++)
	{
	    chksum = chksum + pIp -> pkv[i];
	}

	return;
}