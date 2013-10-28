/*打印符号三角形，符号三角形由+和-组成，两个同号下面是+，两个异号下面是-，运行时需要输入第一行的三角形
eg: + + - -
	 + - +
	  - -
	   +
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
}node;

typedef struct queue{
	node *front;
	node *rear;
}queue;

void initQueue(queue *queuePointer);
char deQueue(queue *queuePointer);
void enQueue(queue *queuePointer, char data);
char peekQueue(queue *queuePointer);

int main(){
	queue *symbols = (queue*)malloc(sizeof(node));
	initQueue(symbols);
	char input;
	int count = 0;
	printf("please input symbols(end by #):\n");
	while(1){
		scanf("%c",&input);
		if(input == '#')
		  break;
		else{
			enQueue(symbols, input);
			count++;
		}
	}
	int i,j,k;
	char nowSymbol,nextSymbol;
	for(i = 0; i < count; i++){
		for(k = 0; k <= i; k++)
		  printf(" ");
		for(j = 0; j < count - i; j++){
			nowSymbol = deQueue(symbols);
			nextSymbol = peekQueue(symbols);
			if(j != count - i - 1){
				if(nowSymbol == nextSymbol){
					enQueue(symbols, '+');
				}
				else{
					enQueue(symbols,'-');
				}
			}
			printf("%c ", nowSymbol);
		}
		printf("\n");
	}
	return 0;
}

void initQueue(queue *queuePointer){
	queuePointer->front = (node*)malloc(sizeof(node));
	queuePointer->rear = queuePointer->front;
}

void enQueue(queue *queuePointer, char data){
	queuePointer->rear->next = (node*)malloc(sizeof(node));
	queuePointer->rear = queuePointer->rear->next;
	queuePointer->rear->data = data;
}

char deQueue(queue *queuePointer){
	char data = queuePointer->front->next->data;
	node *waitFree = queuePointer->front->next;
	queuePointer->front->next = queuePointer->front->next->next;
	free(waitFree);
	return data;
}

char peekQueue(queue *queuePointer){
	return queuePointer->front->next->data;
}
