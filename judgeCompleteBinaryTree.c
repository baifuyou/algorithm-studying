//判断一个二叉树是否是完全二叉树
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}node;

int judge(node *root, int nodeDepth);
void test();
int getTreeDepth(node *root);

int main(){
	test();
	return 0;
}

void test(){
	node *root = (node*)malloc(sizeof(node));
	root->left = (node*)malloc(sizeof(node));
	//root->right = (node*)malloc(sizeof(node));
	root->left->left = (node*)malloc(sizeof(node));
	root->left->right = (node*)malloc(sizeof(node));
	printf("%d\n",judge(root, 1));
}

int judge(node *root, int nodeDepth){
	static int endMark = 0;
	static int treeDepth = 0;
	if(treeDepth == 0){
		treeDepth = getTreeDepth(root);
	}
	if(root->left == NULL){
		if(root->right != NULL)
		  return 0;
		else{
			if(endMark == 1){
				if(nodeDepth < treeDepth - 1){
					return 0;
				}
				else
				  return 1;
			}
			else{
				if(nodeDepth < treeDepth - 1){
					return 0;
				}
				else{
					endMark = 1;
					return 1;
				}
			}
		}
	}
	else{
		if(root->right == NULL){
			if(nodeDepth < treeDepth - 1){
				return 0;
			}
			else{
				endMark = 1;
				return 0;
			}
		}

	}
	return (judge(root->left,nodeDepth+1)&&judge(root->right,nodeDepth+1));
}

int getTreeDepth(node *root){
	int treeDepth = 0;
	node *now = root;
	while(now != NULL){
		treeDepth++;
		now = now->left;
	}
	return treeDepth;
}
