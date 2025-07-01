typedef struct TAG_DIGITAL_GYRO_DATA
{

    int		countPick[9];		 	
    int 	Gi[3];				 
    int 	wa[9];				 
    int 	wal[9];				 
 	int		JoinTotal;          
 	int  	gyroStatus0;		
 	int 	gyroStatus1;		 
    int 	W[3];				 
    int 	SignFlag[9] ; 		   
	int 	Rtemp[3][5];		 
	int 	stateFlag[9];		
	
} SGyroData;
typedef struct __GyroPick
{
	SGyroData*			pGyroData;
} GyroPick;

/*@

ensures a < 0 ==> \result == -a;

ensures a >= 0 ==> \result == a;

*/

int Abs (int a)
{

    int ans = 0;
    if(a<0) {
        ans =-a;
    }else {
        ans = a;
    }

    return ans;
}