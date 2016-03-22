#include <stdio.h>
#define TABSTOP_SIZE 8

/* Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter? */
int main() {
        int c, i = 0; /* current line length */

	while ((c = getchar()) != EOF){
		i++;
		
		if (c == '\n'){
			i = 0;
		}

		if (c == '\t'){
			for (int s = TABSTOP_SIZE - (--i % TABSTOP_SIZE); s > 0; --s) {
				putchar(' ');
				i++;
			}
		} else {
			putchar(c);
		}
	}

        return 0;
}
