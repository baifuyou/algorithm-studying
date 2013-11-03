//计数排序，最多对10个正整数升序排列,并且要求待排序的数字都在1到10之间（含1，含10）

#include <stdio.h>

void countingSort(int *waitSort, int length, int *result);

int main(){
	int waitSort[11], result[11];
	int i, input;
	printf("please input numbers(end by -1):\n");
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if( input == -1)
		  break;
		else
		  waitSort[i] = input;
	}
	int length = i;
	countingSort(waitSort, length, result);
	for(i = 0; i < length; i++)
	  printf("%d,", result[i]);
	printf("\n");
	return 0;
}

void countingSort(int *waitSort, int length, int *result){
	int i;
	int temp[11];
	for(i = 0; i < 10; i++){
		temp[i] = 0;
	}
	for(i = 0; i < length; i++){
		temp[waitSort[i]]++;
	}
	for(i = 1; i < 10; i++){
		temp[i] = temp[i] + temp[i-1];
	}
	for(i = length - 1; i >= 0; i--){
		result[temp[waitSort[i]] - 1] = waitSort[i];
		temp[waitSort[i]] = temp[waitSort[i]] - 1;
	}
}
