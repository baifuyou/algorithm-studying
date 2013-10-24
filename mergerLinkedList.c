//把两个单调不减的链表更并成一个新的单调不减的链表
//要求在原表空间进行
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
	int data;
	struct linkedList *next;
}linkedList;

linkedList *createLinkedList();
void printLinkedList(linkedList *head);
linkedList *merger(linkedList *headA, linkedList *headB);

int main(){
	linkedList *listAHead;
	linkedList *listBHead;
	listAHead = createLinkedList();
	listBHead = createLinkedList();
	linkedList *mergerAfter = merger(listAHead, listBHead); 
	printLinkedList(mergerAfter);
	return 0;
}

linkedList *merger(linkedList *headA, linkedList *headB){
	linkedList *exchange;
	if(headA->data < headB->data){
		exchange = headA;
		headA = headB;
		headB = exchange;
	}
	linkedList *listANow = headA;
	linkedList *listBNow = headB;
	linkedList *listBBefore;
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

linkedList *createLinkedList(){
	printf("please input numbers that are stoped by 0:(eg:2 3 4 5 0)\n");
	linkedList *head = (linkedList*)malloc(sizeof(linkedList));
	linkedList * now = head;
	int input;
	while(1){
		scanf("%d",&input);
		if(input == 0){
			break;
		}
		else{
			now->next = (linkedList*)malloc(sizeof(linkedList));
			now = now->next;
			now->data = input;
		}
	}
	return head->next;
}

void printLinkedList(linkedList *head){
	linkedList *now = head;
	while(now){
		printf("%d,",now->data);
		now = now->next;
	}
	printf("\n");
}
