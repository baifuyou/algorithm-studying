/*实现任意长度的正整数的加法;
  输入：expression#；输出：answer；
  eg：输入：1234+23#；输出：1257
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *prior;
	struct node *next;
}node;

typedef struct stack{
	node *top;
	node *base;
}stack;

void initStack(stack *stackPointer);
void push(stack *stackPointer, char data);
char pop(stack *stackPointer);
int isEmpty(stack *stackPointer);
void printStack(stack *stackPointer);

void add(stack *operand1, stack *operand2, stack *answer);
void addPlace(char place1, char place2, char nowCarry, char *nextCarry, char *sum);

int main(){
	stack *operand1 = (stack*)malloc(sizeof(stack));
	stack *operand2 = (stack*)malloc(sizeof(stack));
	stack *answer = (stack*)malloc(sizeof(stack));
	initStack(operand1);
	initStack(operand2);
	initStack(answer);
	printf("please input your expression(end by #):\n");
	char input;
	stack *operand = operand1;
	while(1){
		scanf("%c", &input);
		if(input == '#')
		  break;
		else{
			if(input == '+'){
				operand = operand2;
				continue;
			}
			else
				push(operand, input);
		}
	}
	add(operand1, operand2, answer);
	printStack(answer);
	return 0;
}

void initStack(stack *stackPointer){
	stackPointer->base = (node*)malloc(sizeof(node));
	stackPointer->top = stackPointer->base;
}

void push(stack *stackPointer, char data){
	stackPointer->top->next = (node*)malloc(sizeof(node));
	stackPointer->top->next->prior = stackPointer->top;
	stackPointer->top = stackPointer->top->next;
	stackPointer->top->data = data;
}

char pop(stack *stackPointer){
	char data = stackPointer->top->data;
	node *waitFree = stackPointer->top;
	stackPointer->top = stackPointer->top->prior;
	free(waitFree);
	return data;
}

int isEmpty(stack *stackPointer){
	return stackPointer->top == stackPointer->base;
}

void printStack(stack *stackPointer){
	while(!isEmpty(stackPointer)){
		printf("%c", pop(stackPointer));
	}
	printf("\n");
}

void add(stack *operand1, stack *operand2, stack *answer){
	char place1, place2, nowCarry = '0', nextCarry = '0', placeSum;
	while((!isEmpty(operand1)) && (!isEmpty(operand2))){
		place1 = pop(operand1);
		place2 = pop(operand2);
		nowCarry = nextCarry;
		addPlace(place1, place2, nowCarry, &nextCarry, &placeSum);
		push(answer, placeSum);
	}
	if(!isEmpty(operand1)){
		place1 = pop(operand1);
		nowCarry = nextCarry;
		addPlace(place1, '0', nowCarry, &nextCarry, &placeSum);
		push(answer, placeSum);
		while(!isEmpty(operand1)){
			push(answer, pop(operand1));
		}
	}
	if(!isEmpty(operand2)){
		place2 = pop(operand2);
		nowCarry = nextCarry;
		addPlace('0', place2, nowCarry, &nextCarry, &placeSum);
		push(answer, placeSum);
		while(!isEmpty(operand2)){
			push(answer, pop(operand2));
		}
	}
	if( (nextCarry != '0') && (nextCarry != ' ') ){
		push(answer, nextCarry);
	}
}

void addPlace(char place1, char place2, char nowCarry, char *nextCarry, char *placeSum){
	int place1Int = atoi(&place1);
	int place2Int = atoi(&place2);
	int nowCarryInt = atoi(&nowCarry);
	int sumInt = place1Int + place2Int + nowCarryInt;
	char sumStr[2];
	sprintf(sumStr, "%2d",sumInt);
	*nextCarry = sumStr[0];
	*placeSum = sumStr[1];
}
