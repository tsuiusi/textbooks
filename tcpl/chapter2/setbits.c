#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
	unsigned x = 0b11110000;
	unsigned y = 0b1010;
	unsigned result = setbits(x, 4, 3, y);
	printf("%u\n", result);
	return 0;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (~(~(~0 << n) << (p + 1 - n)) & x) | (~(~0 << n) & y) << (p + 1 - n);
}
