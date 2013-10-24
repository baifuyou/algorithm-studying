/*使用循环连乘的方法计算m的n次幂，重复执行1000000次和递归计算做速度比较*/
#include <stdio.h>
#include <stdlib.h>

void power(double base, int exponent);

int main(int argc, char **argv){
	if(argc != 3){
		printf("usage:power1 base exponent\n");
		return 0;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	/*int i;
	double result = 1;
	for(i=0; i<exponent; i++){
		result = result*base;
	}
	printf("%f",result);
	printf("\n");*/
	int i;
	for(i = 0; i<1000000; i++){
		power(base, exponent);
	}
	return 0;
}

void power(double base, int exponent){
	//double base = atof(argv[1]);
	//int exponent = atoi(argv[2]);
	int i;
	double result = 1;
	for(i=0; i<exponent; i++){
		result = result*base;
	}
	//printf("%f",result);
	//printf("\n");
}
