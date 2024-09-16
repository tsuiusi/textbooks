#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

#define BUFSIZE 100

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;       // next free position in buf

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn) {
	int c, sign;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		int sign = c;
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(sign);
			return 0;
		}

	}

	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;

	if (c != EOF) {
		ungetch(c);
	}

	return c;
}

float getfloat(float *pn) {
	float c, sign;
	float power;
	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		float sign  = c;
		c = getch();
	}

	for (*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}

	if (c == '.') {
		c = getch();
		for (power = 1.0; isdigit(c); c = getch()) {
			*pn = 10.0 * *pn + (c - '0');
			power *= 10.0;
		}
		*pn /= power;
	}
	
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main() {
	return 0;
}
