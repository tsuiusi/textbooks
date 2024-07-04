#include <stdio.h>

void escape(char s[], char t[]);

void escape(char s[], char t[]) {
	int i, j;

	for (i = 0, j=0; s[i] != '\0'; i++, j++) {
		switch (s[i]) {
			case '\t': 
				t[j++] = '\\';
				t[j] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';				
				break;
			default:
				t[j] = s[i];
	}	
	t[j] = '\0';
}
