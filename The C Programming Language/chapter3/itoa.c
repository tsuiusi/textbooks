#include <stdio.h>
#include <string.h>
#include <math.h>

void itoa(int n, char s[], int b);
void reverse(char s[]);
char bases[] = "0123456789abcdef";

// Only making this up to base 16
void itoa(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {                 /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    reverse(s);
    while (i <= b) {
        s[i++] = ' ';
    }
    s[i] = '\0';
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
    itoa(255, s, 16);
    printf("%s", s);
}
