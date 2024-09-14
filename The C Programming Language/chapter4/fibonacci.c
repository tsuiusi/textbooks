#include <stdio.h>

int fibonacci(int n);

int main() {
	int number;
	printf("number: ");
	scanf("%d", &number); //pointer towards number
	printf("%d\n", fibonacci(number));

	return 0;
}

int fibonacci(int n) {
	if (n <=  1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

