//冒泡排序，最多对10个整数从小到大排序

#include <stdio.h>

int main(){
	int waitSort[11];
	printf("please input numbers(end by -1):\n");
	int input, i, j;
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else
		  waitSort[i] = input;
	}
	waitSort[i] = -1;
	int length = i, temp;
	for(i = 0; i < length; i++){
		for(j = 0; j < length - i - 1; j++){
			if(waitSort[j] > waitSort[j+1]){
				temp = waitSort[j];
				waitSort[j] = waitSort[j+1];
				waitSort[j+1] = temp;
			}
		}
	}
	for(i = 0; waitSort[i] != -1; i++){
		printf("%d,",waitSort[i]);
	}
	printf("\n");
	return 0;
}
