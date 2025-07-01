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
/*@
 requires \valid(pIp) && \valid(pIp->pGyroData) ;
 requires \separated(pIp,pIp->pGyroData) ;

ensures a < 0 ==> \result == -a;

ensures a >= 0 ==> \result == a;

*/

void GyroPickFun(GyroPick *pIp)

{
    int iy = 0;
    int tmpgi;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant \forall integer j; 0 <= j < 9 ==> pIp->pGyroData->stateFlag[j] == \at(pIp->pGyroData->stateFlag[j], Pre);
      loop invariant \forall integer j, k; 0 <= j < 3 && 0 <= k < 5 ==> pIp->pGyroData->Rtemp[j][k] == \at(pIp->pGyroData->Rtemp[j][k], Pre);
      loop invariant \forall integer j; 0 <= j < 9 ==> pIp->pGyroData->SignFlag[j] == \at(pIp->pGyroData->SignFlag[j], Pre);
      loop invariant \forall integer j; 0 <= j < 3 ==> pIp->pGyroData->W[j] == \at(pIp->pGyroData->W[j], Pre);
      loop invariant \forall integer j; 0 <= j < 9 ==> pIp->pGyroData->wal[j] == \at(pIp->pGyroData->wal[j], Pre);
      loop invariant \forall integer j; 0 <= j < 9 ==> pIp->pGyroData->wa[j] == \at(pIp->pGyroData->wa[j], Pre);
      loop invariant \forall integer j; 0 <= j < 3 ==> pIp->pGyroData->Gi[j] == \at(pIp->pGyroData->Gi[j], Pre);
      loop invariant \forall integer j; 0 <= j < 9 ==> pIp->pGyroData->countPick[j] == \at(pIp->pGyroData->countPick[j], Pre);
      loop invariant pIp->pGyroData->gyroStatus1 == \at(pIp->pGyroData->gyroStatus1, Pre);
      loop invariant pIp->pGyroData->gyroStatus0 == \at(pIp->pGyroData->gyroStatus0, Pre);
      loop invariant pIp->pGyroData->JoinTotal == \at(pIp->pGyroData->JoinTotal, Pre);
      loop invariant 0 <= iy <= 9;
      loop invariant pIp == \old(pIp);
    */
    for (; iy < 9; iy++) {
        tmpgi = Abs(pIp->pGyroData->wa[iy] - pIp->pGyroData->wal[iy]);

        if (tmpgi > 0x00000004) {
            pIp->pGyroData->countPick[iy]++;

            if (pIp->pGyroData->countPick[iy] < 6) {
                pIp->pGyroData->wa[iy] = pIp->pGyroData->wal[iy];
            } else {
                pIp->pGyroData->wal[iy] = pIp->pGyroData->wa[iy];
                pIp->pGyroData->countPick[iy] = 0;
            }
        } else {
            pIp->pGyroData->wal[iy] = pIp->pGyroData->wa[iy];
            pIp->pGyroData->countPick[iy] = 0;
        }
    }

    return;
}