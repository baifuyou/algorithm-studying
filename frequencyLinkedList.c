//实现一个按访问频率不升序的循环链表，附带一个test方法

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	int frequency;
	struct node *prior;
	struct node *next;
}node;

node *createLinkedList();
void test();
void visit(node *head,int value);
void printLinkedList(node *head);
void maintain(node *nowa, node *head);

int main(){
	test();
	return 0;
}

void test(){
	node *head = createLinkedList();
	printf("please input values that you want to visit(end by -1):\n");
	int input;
	while(1){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else{
			visit(head, input);
		}
	}
	printLinkedList(head);
}

node *createLinkedList(){
	node *head = (node*)malloc(sizeof(node));
	int length;
	printf("please input linkedList length:\n");
	scanf("%d", &length);
	printf("please input linkedList values:\n");
	int i, value;
	node *now = head;
	for(i = 0; i < length; i++){
		scanf("%d", &value);
		now->next = (node*)malloc(sizeof(node));
		now->next->prior = now;
		now->next->value = value;
		now->frequency = 0;
		now = now->next;
	}
	now->next = head;
	head->prior = now;
	return head;
}

void visit(node *head,int value){
	node *now = head->next;
	while(now != head){
		if(now->value == value){
			now->frequency++;
			maintain(now, head);
			break;
		}
		now = now->next;
	}
}

void maintain(node *now, node *head){
	if(now->prior == head)
	  return;
	node *node1, *node2, *node3, *node4;
	if(now->frequency > now->prior->frequency){
		node1 = now->prior->prior;
		node2 = now;
		node3 = now->prior;
		node4 = now->next;

		node1->next = node2;
		node2->prior = node1;
		node2->next = node3;
		node3->prior = node2;
		node3->next= node4;
		node4->prior = node3;
		maintain(now, head);
	}
}

void printLinkedList(node *head){
	node *now = head->next;
	while(now != head){
		printf("(%d,%d),", now->value,now->frequency);
		now = now->next;
	}
	printf("\n");
}
