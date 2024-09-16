#include <stdio.h>

void swap(int *px, int *py);

int main() {
	int x = 1; 
	int y = 2;
	swap(&x, &y);
	printf("%d", x);
	return 0;
}

void swap(int *px, int *py) {
	int temp = *px;
	*px = *py;
	*py = temp;
}
