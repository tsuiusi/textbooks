#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int limit);

int main() {
	int c, len, i;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		char reverseline[MAXLINE];
		for (i = len - 1; i >= 0; i--) {
			reverseline[i] = line[len - i - 1];
		}
		reverseline[len] = '\n';
		reverseline[len+1] = '\0';
		printf("%s", reverseline);
	}		

	return 0;
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
