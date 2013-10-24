/*打印11-999之间的三重回文数字，
  如果一个整数顺序倒序都是同一个数字就是回文数字
  如果一个整数a是回文数字，a^2,a^3都是回文数字，则这个数字是3重回文数字
  */
#include <stdio.h>

int isReverse(int number);

int main(int argc,char **argv){
	int i;
	printf("11-999有以下这些三重回文数字:\n");
	for(i = 11; i<=999; i++){
		if(isReverse(i) && isReverse(i*i) && isReverse(i*i*i))
		  printf("%d,",i);
	}
	printf("\n");
	return 0;
}

int isReverse(int number){
	int m = number, reverse = 0;
	while(m){
		reverse = reverse*10+m%10;
		m = m/10;
	}
	if(reverse == number)
	  return 1;
	else 
	  return 0;
}
