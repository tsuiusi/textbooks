#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
	unsigned x = 0b10000000;
	printf("%u", rightrot(x, 2));
	return 0;
}

unsigned rightrot(unsigned x, int n) {
	int bits = sizeof(unsigned) * 8;
	n = n % bits;
	// return ((~0 >> n) & (x >> n)) & ((x << (8 - n)) & (~0 << (8-n)));
	return (x >> n) | (x << (bits - n));
}
