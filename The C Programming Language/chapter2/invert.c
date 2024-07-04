#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
	unsigned x = 0b11000011;
	printf("%u", invert(x, 2, 4));
	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	unsigned mask = ~(~0 << n) << (p - n + 1);
	return x ^ mask;
}
