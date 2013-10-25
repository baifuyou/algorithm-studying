//把两个单调不减的链表更并成一个新的单调不减的链表
//要求在原表空间进行
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *createLinkedList();
void printLinkedList(node *head);
node *merger(node *headA, node *headB);

int main(){
	node *listAHead;
	node *listBHead;
	listAHead = createLinkedList();
	listBHead = createLinkedList();
	node *mergerAfter = merger(listAHead, listBHead); 
	printLinkedList(mergerAfter);
	return 0;
}

node *merger(node *headA, node *headB){
	node *exchange;
	if(headA->data < headB->data){
		exchange = headA;
		headA = headB;
		headB = exchange;
	}
	node *listANow = headA;
	node *listBNow = headB;
	node *listBBefore;
	while(listANow){
		if(listBNow == NULL){
			listBBefore->next = listANow;
			break;
		}
		if(listANow->data > listBNow->data){
			listBBefore = listBNow;
			listBNow = listBNow->next;
		}
		else{
			listBBefore->next = listANow;
			listANow = listANow->next;
			listBBefore = listBBefore->next;
			listBBefore->next = listBNow;
		}
	}
	return headB;
}

node *createLinkedList(){
	printf("please input numbers that are stoped by 0:(eg:2 3 4 5 0)\n");
	node *head = (node*)malloc(sizeof(node));
	node *waitFree;
	node * now = head;
	int input;
	while(1){
		scanf("%d",&input);
		if(input == 0){
			break;
		}
		else{
			now->next = (node*)malloc(sizeof(node));
			now = now->next;
			now->data = input;
		}
	}
	waitFree = head;
	head = head->next;
	free(waitFree);
	return head;
}

void printLinkedList(node *head){
	node *now = head;
	while(now){
		printf("%d,",now->data);
		now = now->next;
	}
	printf("\n");
}
