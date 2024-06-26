#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(char *s);

int main() {
	char str[] = "NIHAO SHIJIE";
	lower(str);
	printf("%s", str);
	return 0;
}

void lower(char *s) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (isupper(s[i])) {
			s[i] = tolower(s[i]);
		}
	}
}
