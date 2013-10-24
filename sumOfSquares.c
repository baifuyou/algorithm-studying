/*打印一个数number的x^2+y^2的形式，例如：输入：25，输出：3*3+4*4=25
 *来自《妙趣横生的算法》，书上的代码时间复杂度为O（n^2)
 *这段代码时间复杂度仅为O（n)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isSqrtable(int number);

int main(int argc, char **argv){
	if(argc != 2){
		printf("your arguments is not match\n");
		return 0;
	}
	int i;
	int number = atoi(argv[1]);
	int difference;
	for(i = 1; i < number; i++){
		if(isSqrtable(i)){
			difference = number - i;
			if(isSqrtable(difference) && difference > i){
				printf("%d*%d+%d*%d=%d\n",(int)sqrt(i),(int)sqrt(i),(int)sqrt(difference),(int)sqrt(difference),number);
			}
		}
	}
	return 0;
}

int isSqrtable(int number){
	if( ((int)sqrt(number))*((int)sqrt(number)) == number)
	  return 1;
	else
	  return 0;
}
