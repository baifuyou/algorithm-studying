/*魔王语言翻译，魔王语言由大写的A，B和26个小写字母组成，
  人类语言由26个小写字母组成，
  翻译规则：B->tAdA;A->sae;(#&1&2&3....&n)->#&n#&n-1&n-2....#&1#.(1,2,3...n是下标)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char pop(stack *stackPointer);
void push(stack *stackPointer, char data);
void translate(stack *devilsLanguage, char data);
void pushMulti(stack *stackPointer, char *str);

int main(){
	stack *devilsLanguage = (stack*)malloc(sizeof(stack));
	init(devilsLanguage);
	stack *parenthesis = (stack*)malloc(sizeof(stack));
	init(parenthesis);
	printf("please input devils' language:(end by ';')\n");
	char input;
	char mark = '#';
	while(1){
		scanf("%c", &input);
		if(input == ';')
		  break;
		else{
			if(input != '(' && input != ')'){
				if(mark == '#'){
					translate(devilsLanguage, input);
				}
				else if(mark == '@'){
					mark = input;
				}
				else{
					push(parenthesis, input);
				}
			}
			else if(input == '('){
				mark = '@';
			}
			else if(input == ')'){
				while(parenthesis->size != 0){
					translate(devilsLanguage, mark);
					translate(devilsLanguage, pop(parenthesis));
				}
				translate(devilsLanguage, mark);
				mark = '#';
			}
		}
	}
	node *now = devilsLanguage->head->next;
	while(now != NULL){
		printf("%c",now->data);
		now = now->next;
	}
	printf("\n");
	return 0;
}

void translate(stack *devilsLanguage, char data){
	if(data == 'A'){
		pushMulti(devilsLanguage, "sae");
	}
	else if(data == 'B'){
		pushMulti(devilsLanguage, "tsaedsae");
	}
	else{
		push(devilsLanguage,data);
	}
}

void pushMulti(stack *stackPointer, char *str){
	int length = strlen(str);
	int i;
	for(i = 0; i < length; i++){
		push(stackPointer, str[i]);
	}
}

void init(stack *stackPointer){
	stackPointer->head = (node*)malloc(sizeof(node));
	stackPointer->tail = stackPointer->head;
	stackPointer->size = 0;
}

char pop(stack *stackPointer){
	if(stackPointer->size == 0){
		return 0;
	}
	char data = stackPointer->tail->data;
	node *waitFree = stackPointer->tail;
	stackPointer->tail = stackPointer->tail->front;
	stackPointer->tail->next = NULL;
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
