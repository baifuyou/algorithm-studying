//合并排序，最多对10个正整数从小到大

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *waitSort, int p, int r);//对数组waitSort的下标从p到r的元素进行合并排序
void merge(int *waitMerge, int p, int q, int r);//对数组waitSort的子序列waitSort[p...q]和waitSort[q...r]进行合并

int main(){
	int waitSort[10];
	int input, i;
	printf("please input numbers(end by -1):\n");
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if(input == -1){
			break;
		}
		else{
			waitSort[i] = input;
		}
	}
	waitSort[i] = -1;
	int length = i;
	mergeSort(waitSort, 0, length - 1);
	for(i = 0; waitSort[i] != -1; i++){
		printf("%d,",waitSort[i]);
	}
	printf("\n");
	return 0;
}

void mergeSort(int *waitSort, int p, int r){
	int length, q;
	if(p < r){
		length = r - p + 1;
		q = p + length/2;
		mergeSort(waitSort, p, q - 1);
		mergeSort(waitSort, q, r);
		merge(waitSort, p, q-1, r);
	}
}

void merge(int *waitMerge, int p, int q, int r){
	int *waitMergeA = (int*)malloc(sizeof(int)*(q-p+1));
	int *waitMergeB = (int*)malloc(sizeof(int)*(r-q));
	int i=0, j=0, k=0;
	for(i = 0; i < q - p + 1; i++){
		waitMergeA[i] = waitMerge[p+i];
	}
	for(i = 0; i < r - q; i++){
		waitMergeB[i] = waitMerge[q + i + 1];
	}
	for(i = 0; (i < r - p + 1); i++){
		if((j == q - p + 1) || (k == r - q)){
			if(j == q - p + 1){
				waitMerge[p + i] = waitMergeB[k];
				k++;
			}
			else{
				waitMerge[p + i] = waitMergeA[j];
				j++;
			}
		}
		else{
			if(waitMergeA[j] > waitMergeB[k]){
				waitMerge[p + i] = waitMergeB[k];
				k++;
			}
			else{
				waitMerge[p + i] = waitMergeA[j];
				j++;
			}
		}
	}
	free(waitMergeA);
	free(waitMergeB);
}
