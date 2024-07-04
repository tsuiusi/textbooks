# Chapter 2 notes

## Data types
Data types:
1. char | 1 byte
2. short | 16 bits
3. long | 32 bits
4. double | 64 bits (1 for sign, 11 for exponent, 52 for fraction)
5. int | 1 byte

Signs:
1. Signed
2. Unsigned

One bit in signed numbers is used to determine the sign (1 = +, 0 = -)

So the range for short (unsigned) is -2^16 to 2^16 - 1 whereas short(signed) has range -2^15 to 2^15 - 1

## Constants
Escape sequences:
|Sequence|Definition|
|-|-|
|\a|alert|
|\b|backspace|
|\f|formfeed|
|\n|newline|
|\r|carriage return|
|\t|tab|
|\v|vertical tab|
|\\|backslash|
|\?|question mark|
|\'|single quote|
|\"|double quote|
|\ooo|octal|
|\xhh|hexadecimal|
|\0|EOF|

enum is an alternative to #define, and you can define a lot of things at once. like enumerate but can also produce effect of zip if nothing is defined.

## Bitwise Operators
|Operator|Definition|
|-|-|
|&|bitwise AND|
|||bitwise OR|
|^|bitwise XOR|
|<<|left shift|
|>>|right shift|
|~|one's complement (unary) (1 -> 0, 0 -> 1)|


