#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define BUFSIZE 100
#define MAXVAL 100    /* maximum depth of val stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

int getop(char []);
void push(double);
double pop(void);
int getch(void); 
void ungetch(int);

/* reverse Polish calculator */
int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;

			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(),op2));
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		printf("Debug: Stack top: %.8g\n", val[sp-1]);  // Debug output
	}

	return 0;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') // skip blank spaces
		;

	s[1] = '\0';
	
	printf("Debug getop: initial c = %c\n", c);  // Debug output

	if (!isdigit(c) && c !='.' && c != '-') {
		printf("Debug getop: returning non-number %c\n", c);  // Debug output
		return c; /* not a number */
	}

	i = 0;

	if (c == '-') {
		int next = getch();
		printf("Debug getop: found -, next char = %c\n", next);  // Debug output
		if (isdigit(next) || next == '.') {
			s[i++] = -1 * next;
			c = next;
		} else {
			ungetch(next);
			printf("Debug getop: returning minus sign\n");  // Debug output
			return c;
		}
	}

	if (isdigit(c)) /* collect integer part */ 
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.') {/* collect fraction part */ 
		s[i++] = c;
		while (isdigit(s[i] = c = getch()))
			i++;
	}

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
	
}


int getch(void) {   /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   /* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
