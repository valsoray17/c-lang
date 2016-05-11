#include <stdio.h>
#define TABSTOP_SIZE 4

int entab(int tabstop_size);

/* Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference? */

int entab(int tabstop_size) {
	int c, i = 0;
	
	while ((c = getchar()) != EOF) {
		i++;

	}
}
