//把一串表示二进制数字的字符串转换成对应的表示八进制的字符串

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
	struct node *front;
}node;

typedef struct stack{
	node *head;
	node *tail;
	int size;
}stack;

void init(stack *stackPointer);
char pop(stack *stackPointer, char data);
void push(stack *stackPointer, char data);

char binaryToOctal(char binaryBit1,char binaryBit2, char binaryBit3);


int main(){
	stack *binary = (stack*)malloc(sizeof(stack));
	init(binary);
	stack *octal = (stack*)malloc(sizeof(stack));
	init(octal);
	printf("please input binary string(end by 2,eg:11112:)\n");
	char input;
	while(1){
		scanf("%c",&input);
		if(input == '2')
		  break;
		else{
			push(binary, input);
		}
	}
	char binaryBit1,binaryBit2,binaryBit3,octalBit;
	while(binary->size != 0){
		binaryBit3 = pop(binary, '0');
		binaryBit2 = pop(binary, '0');
		binaryBit1 = pop(binary, '0');
		octalBit = binaryToOctal(binaryBit1, binaryBit2, binaryBit3);
		push(octal, octalBit);
	}
	while(octal->size != 0){
		printf("%c",pop(octal, '0'));
	}
	printf("\n");
	return 0;
}

char binaryToOctal(char binaryBit1, char binaryBit2, char binaryBit3){
	if(binaryBit1 == '0' && binaryBit2 == '0' && binaryBit3 == '0')
	  return '0';
	if(binaryBit1 == '0' && binaryBit2 == '0' && binaryBit3 == '1')
	  return '1';
	if(binaryBit1 == '0' && binaryBit2 == '1' && binaryBit3 == '0')
	  return '2';
	if(binaryBit1 == '0' && binaryBit2 == '1' && binaryBit3 == '1')
	  return '3';
	if(binaryBit1 == '1' && binaryBit2 == '0' && binaryBit3 == '0')
	  return '4';
	if(binaryBit1 == '1' && binaryBit2 == '0' && binaryBit3 == '1')
	  return '5';
	if(binaryBit1 == '1' && binaryBit2 == '1' && binaryBit3 == '0')
	  return '6';
	if(binaryBit1 == '1' && binaryBit2 == '1' && binaryBit3 == '1')
	  return '7';
	return 0;
}

void init(stack *stackPointer){
	stackPointer->head = (node*)malloc(sizeof(node));
	stackPointer->tail = stackPointer->head;
	stackPointer->head->data = '#';
	stackPointer->size = 0;
}

char pop(stack *stackPointer, char defaultValue){
	if(stackPointer->size == 0)
	  return defaultValue;
	char data = stackPointer->tail->data;
	node *waitFree = stackPointer->tail;
	stackPointer->tail = stackPointer->tail->front;
	stackPointer->tail->next= NULL;
	free(waitFree);
	stackPointer->size--;
	return data;
}

void push(stack *stackPointer, char data){
	stackPointer->tail->next = (node*)malloc(sizeof(node));
	stackPointer->tail->next->front = stackPointer->tail;
	stackPointer->tail = stackPointer->tail->next;
	stackPointer->tail->data = data;
	stackPointer->size++;
}
