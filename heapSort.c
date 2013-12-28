//堆排序，最多对10个正整数进行从小到大排序

#include <stdio.h>

void maxHeapify(int *heap, int root, int size);
void buildHeap(int *heap, int size);
int getLeft(int root);
int getRight(int root);

int main(){
	int waitSort[11];
	printf("please input numbers(end by -1):\n");
	int i, input;
	for(i = 0; i < 10; i++){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else
		  waitSort[i] = input;
	}
	waitSort[i] = -1;
	int size = i, temp;
	buildHeap(waitSort, size);
	for( i = size - 1; i > 0; i--){
		temp = waitSort[i];
		waitSort[i] = waitSort[0];
		waitSort[0] = temp;
		maxHeapify(waitSort, 0, i);
	}
	for(i = 0; waitSort[i] != -1; i++)
	  printf("%d,", waitSort[i]);
	printf("\n");
	return 0;
}

void buildHeap(int *heap, int size){
	int i;
	for(i = size/2 - 1; i >= 0; i--){
		maxHeapify(heap, i, size);
	}
}

void maxHeapify(int *heap, int root, int size){
	int left, right, largest, temp, i;
	i = root;
	while(i < size/2){
		left = getLeft(i);
		right = getRight(i);
		if((left < size) && (heap[left] > heap[i])){
			largest = left;
		}
		else{
			largest = i;
		}
		if((right < size) && (heap[right] > heap[largest])){
			largest = right;
		}
		if(largest != i){
			temp = heap[largest];
			heap[largest] = heap[i];
			heap[i] = temp;
			i = largest;
		}
		else{
			break;
		}
	}
}

int getLeft(int root){
	return root*2+1;
}

int getRight(int root){
	return root*2+2;
}
