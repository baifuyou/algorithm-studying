//打印输入字符的全排列

#include <stdio.h>

void permutation(char *str, int length, int mark);
void swap(char *str, int i, int j);//交换数组str的下标为i和j的两个元素

int main(){
	printf("please input characters(end by #):\n");
	char input;
	int i;
	char str[100];
	for(i = 0; ;i++){
		scanf("%c",&input);
		if(input == '#'){
			break;
		}
		else{
			str[i] = input;
		}
	}
	int length = i;
	permutation(str, length, 0);
	return 0;
}

void permutation(char *str, int length, int mark){
	int i;
	if(mark == length - 1){
		for(i = 0; i < length; i++){
			printf("%c ",str[i]);
		}
		printf("\n");
	}
	else{
		for(i = mark; i < length; i++){
			swap(str, mark, i);
			permutation(str, length, mark+1);
			swap(str, mark, i);
		}
	}
}

void swap(char *str, int i, int j){
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}
