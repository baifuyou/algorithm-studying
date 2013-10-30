//选择排序，最多对10个整数从小到大排序

#include <stdio.h>

int main(){
	int waitSort[11];
	printf("please input numbers(end by -1):\n");
	int input, i, j, temp;
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else{
			waitSort[i] = input;
		}
	}
	waitSort[i] = -1;
	for(i = 0; waitSort[i] != -1; i++){
		for(j = i; waitSort[j] != -1; j++){
			if(waitSort[i] > waitSort[j]){
				temp = waitSort[i];
				waitSort[i] = waitSort[j];
				waitSort[j] = temp;
			}
		}
		//printf("%d",waitSort[i]);
	}
	//printf("\n");
	for(i = 0; waitSort[i] != -1; i++){
		printf("%d,",waitSort[i]);
	}
	printf("\n");
	return 0;
}

