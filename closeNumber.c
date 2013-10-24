/*计算亲密数，如果整数A的因子和（含1，不含A，下同）等于B的因子和，
  同时B的因子和等于A的因子和则称A和B是亲密数
*/
#include <stdio.h>
#include <stdio_ext.h>

void fillDivisorSums();
int calculateDivisorSum();

int main(void){
	int divisorSums[3000];
	fillDivisorSums(divisorSums);
	int i,targetA,targetB;
	for(i = 0; i<3000; i++){
		targetA = i+1;
		if(divisorSums[i] >= 3000)
		  continue;
		targetB = divisorSums[i];
		if(targetA == divisorSums[targetB-1])
		  printf("(%d,%d)",targetA,targetB);
	}
	return 0;
}

void fillDivisorSums(int *divisorSums){
	int i;
	for(i = 1; i<=3000; i++){
		divisorSums[i-1] = calculateDivisorSum(i);
	}
}

int calculateDivisorSum(int number){
	int i, sum=0;
	for(i = 1; i<number; i++){
		if(number%i == 0)
		  sum = sum + i;
	}
	return sum;
}
