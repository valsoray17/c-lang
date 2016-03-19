#include <stdio.h>
#define FILTER 5
#define TRUE 1
#define FALSE 0

int getline1(char line[], int maxline);
int is_whole_line(char line[], int len, int size);
void copy(char to[], char from[]);

/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
int main()
{
	int len, c; /* current line length */
	char line[FILTER]; /* current input line */

	while ((len = getline1(line, FILTER)) > 0) {
		if (is_whole_line(line, len, FILTER) == FALSE) {
			printf("%s", line);
			while ((c = getchar()) != EOF && c != '\n')
				putchar(c);
			if (c == '\n')
				putchar(c);
		}
	}

	return 0;
}

int is_whole_line(char line[], int len, int size){
	return (len < size - 1 || line[len - 1] == '\n') ? TRUE : FALSE;
}

/* getline: read a line into s, return length */
int getline1(char s[],int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
