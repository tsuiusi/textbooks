#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main() {
	char s1[100], s2[200];
	strcpy(s1, "nihao shijie 0-9");
	expand(s1, s2);
	printf("%s", s2);
}

void expand(char s1[], char s2[]) {
	int i, j;
	char prev, next;

	for (i=0, j=0; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && i > 0 && s1[i+1] != '\0'){
			prev = s1[i-1];
			next = s1[i+1];

			if (prev < next) {
				for (char c = prev + 1; c < next; c++) {
					s2[j++] = c;
				}
			}
		} else {
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}
