#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAXLINE 1000

int main() {
	double sum, atof(char[]);
	char line[MAXLINE];
	int get_line(char line[], int max);

	sum = 0;
	while (get_line(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += atof(line));
	}

	return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, sign2, ecount = 1;
	bool e = false;

	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e')
		i++;
		e = true;

	if (e) {
		sign2 = (s[i] == '-') ? -1 : 1;
		ecount *= sign2;
		if (s[i] == '+' || s[i] == '-')
			i++;

		while (isdigit(s[i])) {
			ecount = ecount * 10 + (s[i] - '0');
			i++;
		}
		return (sign * val / power) * pow(10, sign2 * ecount);	
	
	} else {
		return sign * val / power;
	}
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}
