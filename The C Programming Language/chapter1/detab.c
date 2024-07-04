#include <stdio.h>
#define MAXLINE 1000
#define n 4

int get_line(char s[], int limit);

int main() {
	int c, incr;
	int no_spaces;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			no_spaces = (incr + 4) 	% n;
			for (int i = 0; i <= no_spaces; i++) {
				putchar(' ');
			}
			incr += no_spaces;
		} else {
			putchar(c);
			incr++;
		}
	}
}


int get_line(char s[], int limit) {
	int i, c;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
