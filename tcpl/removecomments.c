#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int get_line(char s[], int limit);

int main() {
	int c;
	char line[MAXLINE];

	while ((c = get_line(line, MAXLINE)) > 0) {
		printf("%s", line);	
		if (line[c - 1] != '\n') {
			printf("\n");
		}
	}
	return 0;
}

int get_line(char s[], int limit) {
	int i, c;
	int counter = 0;
	char prevchar = '\0'; 
	bool comment = false;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF; ++i) {
		if (!comment && prevchar == '/' && (c == '*' || c == '/')) {
			comment = true;
			counter--;
		} else if (comment && (prevchar == '*' || prevchar == '/') && c == '/') {
			comment = false;	
			continue;
		} else if (!comment) {
			s[counter++] = c;
		}
		prevchar = c;

		if (c == '\n') {
			break;
		}
	}
	s[counter] = '\0';

	if (c == EOF && counter == 0) {
		return 0;
	}

	return counter;
}

