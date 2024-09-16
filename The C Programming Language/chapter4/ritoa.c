#include <stdio.h> 
#include <string.h>

void printd(int n);
void ritoa(int n, char s[], int *index);
void reverse(char s[]);
void rreverse(char s[], int *index, int j);

int main() {
	char s[20];
	int index = 0;
	int number;
	printf("Enter an integer to convert: ");
	scanf("%d", &number);

	ritoa(number, s, &index);
	printf("%s", s);
	return 0;
}

// change the first digit in the int into string, do the same to remainder?
void ritoa(int n, char s[], int *index) { // pointer to integer index
	if (n  < 0){
		s[(*index)++] = '-';
		n = -n;
	}

	if (n / 10) {
		ritoa(n/10, s, index);
	}

	s[(*index)++] = n % 10 + '0';
	s[*index] = '\0';
}

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void rreverse(char s[], int *index, int j) {
	// probably iteratively go in
	if (*index >= j) return;
	char c = s[*index];
	s[*index] = s[j];
	s[j] = c;

	(*index)++;
	rreverse(s, index, j - 1);
	// int n = sizeof(s);
	// if (index < (j=n - index)) {
	// 	c = j;
	// 	s[j] = s[index];
	// 	s[index++] = c;
	// 	rreverse(s, index);
	// }
}
	

/* printd: print n in decimal */ 
void printd (int n) {
	if (n < 0) {
		putchar ('-');
		n=-n; 
	}
	if (n / 10) 
		printd(n / 10);

	putchar(n %10 +'0'); 
}
