
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
    int 	SignFlag[9]; 		   
	int 	Rtemp[3][5];		 
	int 	stateFlag[9];		
	
} SGyroData;

typedef struct __GyroPick
{
	SGyroData*			pGyroData;
} GyroPick;

/*@
    ensures \result >= 0; // The result is non-negative
    ensures \result == (a < 0 ? -a : a); // The result is the absolute value of 'a'
*/
int ABS (int a){

    int ans = 0;
    if(a < 0) {
        ans = -a; // Corrected variable name from 'abs' to 'ans'
    } else {
        ans = a; // Corrected variable name from 'abs' to 'ans'
    }

    return ans;
}
