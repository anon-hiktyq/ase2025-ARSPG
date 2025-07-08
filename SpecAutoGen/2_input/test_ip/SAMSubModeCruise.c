


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

typedef struct __SAMSubModeCruise
{
	const int			countMode;
	SFWarning			mFWarning;
	int      		    Count160ms;

} SAMSubModeCruise;

void SAMSubModeCruiseFun(SAMSubModeCruise *pIp)
{

	if (pIp -> countMode == 4000)
	{
		pIp -> mFWarning.CWsp = 1 ;
	}

	return ;
}