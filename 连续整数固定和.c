/*打印一个整数的连续整数固定和，如:
   输入：27
   输出：
	3+...+7=27
	8+...+10=27
	13+...+14=27
	题目来自妙趣横生的算法
*/

#include <stdio.h>
#include <stdlib.h>

void calculate(int num);

int main(int argc, char **argv){
	if(argc != 2){
		printf("arguments is not match!\n");
		return 0;
	}
	calculate(atoi(argv[1]));
	return 0;
}

void calculate(int num){
	int i, j, sum = 0;
	int loopMax = num/2;
	for(i = 1; i <= loopMax; i++){
		sum = 0;
		for(j = i; j <= loopMax+1; j++){
			sum = sum + j;
			if(sum > num)
				break;
			else if(sum == num){
				printf("%d+...%d=%d\n",i,j,num);
			}
			else
			  continue;
		}
	}
}
