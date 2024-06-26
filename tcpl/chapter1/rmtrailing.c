#include <stdio.h>
#define MAXLINE 1000

/*
 * append each line of input into an array, split the elements via \n
 * process the array as a batch
 * print
*/
int get_line(char s[], int limit);

int main() {
	int len, i;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		i = len - 1;
		while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
			--i;
		}
		if (i >= 0) {
			line[i+1] = '\n';
			line[i+2] = '\0';
			printf("%s", line);
		}
	}
	return 0;

}
int get_line (char s[], int limit) {
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

