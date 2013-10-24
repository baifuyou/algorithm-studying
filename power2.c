/*用递归求m的n次幂,重复执行1000000次和循环连乘做速度比较*/
#include <stdio.h>
#include <stdlib.h>

double power(double base, int exponent);
int main(int argc, char **argv){
	if(argc != 3){
		printf("usage:power2 base exponent\n");
		return 0;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	int i;
	for(i = 0; i < 1000000; i++)
		power(base, exponent);
	//printf("%f\n",result);
	return 0;
}

double power(double base, int exponent){
	if(exponent == 1)
	  return base;
	if(exponent%2 == 0)
	  return power(base, exponent/2)*power(base, exponent/2);
	else
	  return power(base, exponent-1)*base;
}
