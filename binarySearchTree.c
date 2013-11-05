//二叉找书的实现，包括一个测试函数,要求key是唯一的

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;

void test();

node *search(node *root, int key);
node *minimum(node *root);
node *maximum(node *root);
node *predecessor(node *root, int key);
node *successor(node *root, int key);
void insert(node *root, int key);
void delete(node *root, int key);
void printBinaryTree(node *root);

int main(){
	test();
	return 0;
}

void test(){
	node *root = (node*)malloc(sizeof(node));
	printf("\ntest insert\n");
	printf("please input numbers(end by -1):\n");
	scanf("%d", &root->key);
	int input;
	while(1){
		scanf("%d", &input);
		if(input == -1)
		  break;
		else
		  insert(root, input);
	}
	printBinaryTree(root);
	printf("\n");

	printf("\ntest search\n");
	printf("please input key:\n");
	int tempKey;
	scanf("%d", &tempKey);
	node *searchResult = search(root, tempKey);
	if(searchResult != NULL)
	  printf("%d\n", searchResult->key);
	else
	  printf("this key is no exist!\n");

	printf("\ntest minimum\n");
	printf("%d\n", minimum(root)->key);

	printf("\ntest maximum\n");
	printf("%d\n", maximum(root)->key);

	printf("\ntest predecessor\n");
	printf("please input key:\n");
	scanf("%d", &tempKey);
	node *predecessorx = predecessor(root, tempKey);
	if(predecessorx != NULL)
	  printf("%d\n", predecessorx->key);
	else
	  printf("this predecessor is no exist!\n");

	printf("\ntest successor\n");
	printf("please input key:\n");
	scanf("%d", &tempKey);
	node *successorx = successor(root, tempKey);
	if(successorx != NULL)
	  printf("%d\n", successorx->key);
	else
	  printf("this successor is no exist!\n");

	printf("\ntest delete\n");
	printf("please input key:\n");
	scanf("%d", &tempKey);
	delete(root, tempKey);
	printBinaryTree(root);
	printf("\n");
}

void printBinaryTree(node *root){
	if(root == NULL){
		return;
	}
	printBinaryTree(root->left);
	printf("%d,", root->key);
	printBinaryTree(root->right);
}

node *search(node *root, int key){
	node *x = root;
	if(x == NULL)
	  return x;
	if(x->key == key)
	  return x;
	else if(key < x->key)
	  return search(x->left, key);
	else
	  return search(x->right, key);
	return NULL;
}

node *minimum(node *root){
	node *x = root;
	while(x->left != NULL)
	  x = x->left;
	return x;
}

node *maximum(node *root){
	node *x = root;
	while(x->right != NULL)
	  x = x->right;
	return x;
}

node *predecessor(node *root, int key){
	node *predecessorx;
	node *x = search(root, key);
	if(x->left != NULL){
		predecessorx = maximum(x->left);
	}
	else{
		while( (x->parent != NULL) && (x->parent->left == x) )
		  x = x->parent;
		predecessorx = x->parent;
	}
	return predecessorx;
}

node *successor(node *root, int key){
	node *successorx;
	node *x = search(root, key);
	if(x->right != NULL){
		successorx = minimum(x->right);
	}
	else{
		while( (x->parent != NULL) && (x->parent->right == x))
		  x = x->parent;
		successorx = x->parent;
	}
	return successorx;
}

void insert(node *root, int key){
	node *x = root;
	while(1){
		if(key > x->key){
			if(x->right != NULL){
				x = x->right;
			}
			else{
				x->right = (node*)malloc(sizeof(node));
				x->right->key = key;
				x->right->parent = x;
				break;
			}
		}
		else{
			if(x->left != NULL){
				x = x->left;
			}
			else{
				x->left = (node*)malloc(sizeof(node));
				x->left->key = key;
				x->left->parent = x;
				break;
			}
		}
	}
}

void delete(node *root, int key){
	node *x = search(root, key);
	node *successorx;
	int temp;
	if(x == NULL)
	  return;
	if( (x->left == NULL) && (x->right == NULL)){
		if(x->parent->left == x){
			x->parent->left = NULL;
		}
		else{
			x->parent->right = NULL;
		}
		free(x);
	}
	else if(x->left == NULL){
		if(x->parent->left == x){
			x->parent->left = x->right;
		}
		else{
			x->parent->right = x->right;
		}
		free(x);
	}
	else if(x->right == NULL){
		if(x->parent->left == x){
			x->parent->left = x->left;
		}
		else{
			x->parent->right = x->left;
		}
		free(x);
	}
	else{
		successorx = successor(root, key);
		temp = successorx->key;
		delete(root, temp);
		x->key = temp;
	}
}
