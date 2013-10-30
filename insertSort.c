//直接插入排序,最多对10个整数从小到大排序
#include <stdio.h>

int main(){
	printf("please input numbers(end by -1):\n");
	int input;
	int waitSort[11];
	int i, j, temp;
	for(i = 0; i < 10; i++){
		scanf("%d",&input);
		if(input == -1){
		  break;
		}
		waitSort[i] = input;
	}
	waitSort[i] = -1;
	for(i = 0; waitSort[i] != -1; i++){
		for(j = i; j >= 0; j--){
			if(waitSort[j] <= waitSort[j-1]){
				temp = waitSort[j-1];
				waitSort[j-1] = waitSort[j];
				waitSort[j] = temp;
			}
			else
			  break;
		}
	}
	for(i = 0; waitSort[i] != -1; i++){
		printf("%d,",waitSort[i]);
	}
	printf("\n");
	return 0;
}
