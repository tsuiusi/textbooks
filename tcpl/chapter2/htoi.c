#include <stdio.h>

int htoi(const char *s);

int main() {
	printf("%d\n", htoi("FFFFFF"));
	return 0;
}

int htoi(const char *s) {
	int result = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		s += 2;
	}

	while (*s != '\0') {
		int digit_value;
		switch (*s) {
			case '0': case '1': case '2': case '3': case '4':case '5': case '6': case '7': case '8': case '9':
                		digit_value = *s - '0';
                		break;
			case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
				digit_value = *s - 'a' + 10;
				break;
			case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
				digit_value = *s - 'A' + 10;
				break;
			default:
				return 0;
		}
		printf("%d\n", digit_value);

		result = result * 16 + digit_value;

		s++;
	}
	return result;
}
