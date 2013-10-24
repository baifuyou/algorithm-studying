/*约瑟夫环。与一般的约瑟夫环不太一样。
  有n个人编号1-n，每个人带一个key，有一个初始m，从第一个人开始顺时针报数
  报到m的人出列，以这个人的key作为m，从这个人的下一个人开始从1重新报数，
  ，，，，
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
	int number; //编号
	int key;
	struct linkedList *next;
}linkedList;

linkedList *createLinkedList();//创建一个约瑟夫环，返回编号最大的节点

int main(){
	linkedList *before = createLinkedList();
	linkedList *now = before->next;
	int m,i;
	printf("please input a m value:\n");
	scanf("%d", &m);
	for(i = 1; now->next != now; i++){
		if(i == m){
			before->next = now->next;
			m = now->key;
			free(now);
			i = 0;
			now = before->next;
		}
		else{
			before = now;
			now = now->next;
		}
	}
	printf("%d\n",now->number);
	return 0;
}

linkedList *createLinkedList(){
	linkedList *circle = (linkedList*)malloc(sizeof(linkedList));
	linkedList *now = circle;
	linkedList *waitFree;
	int input,i;
	printf("please input some keys end by 0:\n");
	for(i = 1; ;i++){
		scanf("%d", &input);
		if(input == 0)
		  break;
		else{
			now->next = (linkedList*)malloc(sizeof(linkedList));
			now = now->next;
			now->number = i;
			now->key = input;
		}
	}
	waitFree = circle;
	circle = circle->next;
	free(waitFree);
	now->next = circle;
	return now;
}
