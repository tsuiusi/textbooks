#include <stdio.h>
#define MAXLINE 1000
#define n 4

int get_line(char s[], int limit);

int main() {
	int c;
	char line[MAXLINE];

	while ((c = get_line(line, MAXLINE)) > 0) {
	}
	return 0;
}


int get_line(char s[], int limit) {
	int i, c;
	int counter = 0;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		putchar(c);
		if (c != ' ') {
			counter++;
		}

		if (counter == n) {
			putchar('\n');
			counter = 0;
		}
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
