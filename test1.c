#include <stdio.h>
#include <time.h>

int main(){
	long start1,start2,stop1,stop2;
	unsigned int i, result;
	start1 = time(NULL);
	for(i = 0; i < 3000000000; i++){
	  result = 2*2;
	  result = result*result;
	}
	stop1 = time(NULL);
	printf("%ld\n",stop1-start1);
	start2 = time(NULL);
	for(i = 0; i < 3000000000; i++){
	  result = 2*2*2*2;
	}
	stop2 = time(NULL);
	printf("%ld\n",stop2-start2);
	return 0;
}
