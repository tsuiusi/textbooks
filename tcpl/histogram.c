#include <stdio.h>
#define MAX_WORD_LENGTH 21

int main() {
	int c, nl, i, j;
	int nletters[MAX_WORD_LENGTH + 1];
	
	nl = 0;

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		nletters[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			++nl;
		} else {
			if (nl > 0) {
				if (nl <= MAX_WORD_LENGTH) {
					++nletters[nl];
				} else {
					++nletters[MAX_WORD_LENGTH];
				}
				nl = 0;
			}
		}
	}
	
	if (nl > 0) {
		if (nl <= MAX_WORD_LENGTH) {
			++nletters[nl];
		} else {
			++nletters[MAX_WORD_LENGTH];
		}
	}	

	for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
		printf("%2d | ", i);

		for (j = 0; j < nletters[i]; ++j) {
			putchar('X');
		}
		putchar('\n');
	}

	return 0;
}
