/*用非递归方式解这个方程：f(n) = n+1,n=0;f(n) = nf(n/2);
  ‘/’是指整除，n是大于等于0的整数
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *prior;
	struct node *next;
}node;

typedef struct stack{
	node *top;
	node *base;
}stack;

void initStack(stack *stackPointer);
void push(stack *stackPointer, int data);
int pop(stack *stackPointer);

int main(int argc, char **argv){
	if(argc != 2){
		printf("arguments do not match\n");
		return 0;
	}
	stack *answers = (stack*)malloc(sizeof(node));
	initStack(answers);
	int operand = atoi(argv[1]);
	while(1){
		if(operand != 0){
			push(answers, operand);
			operand = operand/2;
		}
		else{
			push(answers, 1);
			break;
		}
	}
	int answer = 1,subAnswer = 1;
	while(answers->top != answers->base){
		subAnswer = pop(answers);
		answer = answer * subAnswer;
	}
	printf("%d\n",answer);
	return 0;
}

void initStack(stack *stackPointer){
	stackPointer->base = (node*)malloc(sizeof(node));
	stackPointer->top = stackPointer->base;
}

void push(stack *stackPointer, int data){
	stackPointer->top->next = (node*)malloc(sizeof(node));
	stackPointer->top->next->prior = stackPointer->top;
	stackPointer->top = stackPointer->top->next;
	stackPointer->top->data = data;
}

int pop(stack *stackPointer){
	int data = stackPointer->top->data;
	node *waitFree = stackPointer->top;
	stackPointer->top = stackPointer->top->prior;
	free(waitFree);
	return data;
}
