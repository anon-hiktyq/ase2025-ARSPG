typedef struct TAG_FAULT_WARNING
{
 	int CWsp;
 	int CWtf;

    int Wsp;
    int Wtf;
    int Wav;

    int flgups;
    int flgModeChange;

    int countAV;
    int countSPLost;
    int countSPSeen;
    int countSPset;
    int countUPSpc;

} SFWarning;
typedef struct TAG_DSS_DATA
{
 	int stateFlag_A;
 	int stateFlag_B;
 	int royaw;
 	int piyaw;
	int flgSP;
}SDSSData;
typedef struct TAG_CONTROLLERIN
{
    
    int 	Up;						
    int 	Ud;					
    int 	fy;					
    
}SController;
typedef struct __SAMSubModeRoll
{
/* 输入端口 */
	SDSSData * pSDS;
	int		countPublic;
	int		countMode;
	int     flgMode;
	/* 输出端口 */
	SDSSData		mDSSData;
	/* 输入输出端口 */
	SController*	pCtrl0;
	SController*	pCtrl1;
	SController*	pCtrl2;
	int			    flgPRSAM;
	SFWarning		mFWarning;
	/* 状态变量 */
	/* 参数变量 */
} SAMSubModeRoll;

/*@

ensures x >= 0 ==> \result == x;

ensures x < 0 ==> \result == -x;

*/

int ABS(int x)

{
	if (x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}