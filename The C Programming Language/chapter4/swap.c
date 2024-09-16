#include <stdio.h>
#include <stddef.h> // 
// #define swap(a, b) (c = a)\(a = b)\(b = c)
#define swap(T, a, b) do {\
	T c = (a); \
	a = (b); \
	b = c; \
} while (0)

int main() {
	int x = 1;
	int y = 2;
	swap(int, x, y);
	printf("%d", x);
	printf("%d", y);
}
	
