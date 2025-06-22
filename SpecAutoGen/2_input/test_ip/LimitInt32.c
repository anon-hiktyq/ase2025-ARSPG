

typedef struct __LimitInt32
{
/* 接口函数 */
	int			in;
	int		    bound;
	/* 输出端口 */
	int		    value;
	int*		ret;
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} LimitInt32;


void LimitInt32Fun(LimitInt32 *pIp)
{

    if (pIp -> in > pIp -> bound)
    {
        pIp -> value = pIp -> bound ;
    }
    else if (pIp -> in < -pIp -> bound)
    {
        pIp -> value = -pIp -> bound ;
    }
    else
    {
        pIp -> value = pIp -> in ;
    }

    *(pIp -> ret) = pIp -> value ;


}