//装配线调度问题，问题详情见《算法导论》（机械工业出版社，原书第二版）192页，15.1 装配线调度问题

#include <stdio.h>


int line1Time[6] = {7, 9, 3, 4, 8, 4};
int line2Time[6] = {8, 5, 6, 4, 5, 7};
int line1ChangeTime[7] = {2, 2, 3, 1, 3, 4, 3};//第一个和最后一个时间表示进入和退出时间，下同
int line2ChangeTime[7] = {4, 2, 1, 2, 2, 1, 2};

int dispatch(int nowStation, int nowLine);

int main(){
	int bestTime;
	int lastStationBestTime1 = dispatch(5, 1);
	int lastStationBestTime2 = dispatch(5, 2);
	if( (lastStationBestTime1 + line1ChangeTime[6]) < (lastStationBestTime2 + line2ChangeTime[6]) ){
		bestTime = lastStationBestTime1 + line1ChangeTime[6];
	}
	else{
		bestTime = lastStationBestTime2 + line2ChangeTime[6];
	}
	printf("%d\n", bestTime);
	return 0;
}

int dispatch(int nowStation, int nowLine){
	if(nowStation == 0){
		if(nowLine == 1)
		  return line1Time[nowStation] + line1ChangeTime[nowStation];
		else
		  return line2Time[nowStation] + line2ChangeTime[nowStation];
	}
	int bestTime;
	int priorStation = nowStation - 1;
	int line1PriorBestTime = dispatch (priorStation, 1);
	int line2PriorBestTime = dispatch (priorStation, 2); 
	if(nowLine == 1){
		if(line1PriorBestTime < ( line2PriorBestTime + line2ChangeTime[nowStation]) ){
			bestTime = line1PriorBestTime + line1Time[nowStation];
		}
		else{
			bestTime = line2PriorBestTime + line2ChangeTime[nowStation] + line1Time[nowStation];
		}
	}
	else{
		if(line2PriorBestTime < ( line1PriorBestTime + line1ChangeTime[nowStation]) ){
			bestTime = line2PriorBestTime + line2Time[nowStation];
		}
		else{
			bestTime = line1PriorBestTime + line1ChangeTime[nowStation] + line2Time[nowStation];
		}
	}
	return bestTime;
}
