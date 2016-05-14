#include <stdio.h>
#define TABSTOP_SIZE 8

int entab(int tabstop_size);

/* Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference? */
int main() {
	entab(TABSTOP_SIZE);
	return 0;
}

int entab(int tabstop_size) {
	int c, cols = 0, whites = 0;
	
	while ((c = getchar()) != EOF) {
		cols++;
		
		if (c == '\t') {
			cols += tabstop_size - cols % tabstop_size;
		}

		if (c == '\n') {
			cols = 0;
		}
		
		if (c != ' ') {
			for (; whites > 0; whites--) {
				putchar(' ');
			}
			putchar(c);
		} else {
			whites++;
			if (cols % tabstop_size == 0){
				whites = 0;
				putchar('\t');
			}
		}
	}
}
