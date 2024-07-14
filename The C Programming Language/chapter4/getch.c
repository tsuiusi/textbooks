#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
char buf[BUFSIZE];
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

int bufp = 0;
int sp = 0; /* max depth of val stack */
double val[MAXVAL];

int main() {
	int type;
	char v;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				printf("%f\n", val[--sp]);
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
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("Error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0) {
					push(fmod(pop(), op2));
				} else {
					printf("Error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;

			case 'P':
				printf("Top of the stack: %f\n", top());
				break;
			case 'D':
				duplicate();
				printf("Duplicated!\n");
				break;
			case 'S':
				swap();
				printf("Swapped!\n");
				break;
			case 'C':
				clear();
				printf("Cleared!\n");
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'p':
				push(pow(pop(), pop()));
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
		printf("%f\n", val[sp - 1]);
	}
}

/* push f onto value stack */
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("Error: stack full, can't push %g\n", f);
	}
}

/* pop and return top value from stack */
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

/* get next operator/numeric operand */
int getop(char s[]) {
	int i, c;
	bool neg = false;

	while ((s[0] = c = getch()) == ' '||c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}
	
	i = 0;
	if (c == '-' && !isdigit(s[++i] = c = getch())) {
		ungetch(c);
		c = s[0];
	}	
	if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())) 
				;
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) 
				;
	}

	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	} 

	return NUMBER;
}

/* get a character */
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}
	
double top(void) {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void) {
	push(top());
}

void swap(void) {
	double swapped;
	int i;
	
	if (sp < 2) {
		printf("Not enough elements to be duplicated");
	} else {
		i = sp - 1;
		swapped = val[i-1];
		val[i-1] = val[i];
		val[i] = swapped;
	}
}

void clear(void) {
	while (--sp >= 0) {
		val[sp] = 0.0;
	}
	sp = 0;
}
