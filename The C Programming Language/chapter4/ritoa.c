#include <stdio.h> 

void printd(int n);
void ritoa(int n, char s[]);

int main() {
	printd(1234234);
	return 0;
}

// change the first digit in the int into string, do the same to remainder?
void ritoa(int n, char s[], int *index) {
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

void rreverse(char s[]) {
	

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
