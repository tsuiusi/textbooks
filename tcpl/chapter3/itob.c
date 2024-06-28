#include <stdio.h>
#include <string.h>
#include <math.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
char bases[] = "0123456789abcdef";

// Only making this up to base 16
void itob(int n, char s[], int b) {	
	int i, c;
	int min = 0;
	
	if (n==0) {
		s[i++] = 0;
		s[i] = '\0';
		return;
	}

	while (n > 0) {
		s[i++] = bases[n % b];
		n /= b;
	}	
	s[i++] = '\0';
	reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main() {
	char s[100];
	itob(255, s, 16);
	printf("%s", s);
}
