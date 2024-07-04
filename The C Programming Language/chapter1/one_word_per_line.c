#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
		} else {
			putchar('\n');
		}
	}
	
	return 0;
}
