#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define FILTER 80

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
int
main()
{
        int len; /* current line length */
        int max; /* maximum length seen so far */
        char line[MAXLINE]; /* current input line */

        max = 0;
        while ((len = getline1(line, MAXLINE)) > 0)
                if (len > FILTER) {
                        printf("%s", line);
                }

        return 0;
}

/* getline: read a line into s, return length */
int
getline1(char s[],int lim)
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
