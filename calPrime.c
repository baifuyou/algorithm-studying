#include <stdio.h>

#define LIMIT 100000000
char nums[LIMIT + 1];

int next(int index) {
	int i;
	for (i = index + 1; i <= LIMIT; i++) {
		if (nums[i] == 0) {
			return i;
		}
	}
	return i;
}

int main() {
	long long p;
	nums[0] = 1;
	nums[1] = 1;
	int primeCount = 0;
	long long i;
	for (p = 2; p <= LIMIT; p = next(p)) {
		//printf("%lld, ", p);
		primeCount++;
		for (i = p * p; i <= LIMIT; i = i + p) {
			//printf("(%d, %lld)", p, i);
			//if (i < 0) return 0;
			nums[i] = 1;
		}
	}
	printf("\n");
	printf("count: %d\n", primeCount);
	return 0;
}

