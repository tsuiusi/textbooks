#include <stdio.h>
#include <math.h>

int power(int m, int n);

int main() {
	int i; 

	for (i = 0; i < 10; ++i) {
		printf("%d %d %d\n", i, power(2,i), power (-3,i));
	}
	return 0;
}

int power(int base, int n) {
	return pow(base, n);	
}
