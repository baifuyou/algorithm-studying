//快速排序，最多对10个正整数数进行从小到大的排序

#include <stdio.h>

void quickSort(int *waitSort, int start, int end);

int main(){
	int waitSort[11];
	int i, input;
	printf("please input numbers(end by -1):\n");
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else
		  waitSort[i] = input;
	}
	waitSort[i] = -1;
	quickSort(waitSort, 0, i-1);
	for(i = 0; waitSort[i] != -1; i++){
		printf("%d,", waitSort[i]);
	}
	printf("\n");
	return 0;
}

void quickSort(int *waitSort, int start, int end){
	if(start >= end)
	  return;
	int standard = waitSort[start];
	int i = start, j = end;
	while(i < j){
		while((i < j)){
			if(waitSort[j] < standard){
				waitSort[i] = waitSort[j];
				break;
			}
			j--;
		}
		while((i < j)){
			if(waitSort[i] > standard){
				waitSort[j] = waitSort[i];
				break;
			}
			i++;
		}
	}
	waitSort[i] = standard;
	quickSort(waitSort, start, i - 1);
	quickSort(waitSort, i + 1, end);
}
