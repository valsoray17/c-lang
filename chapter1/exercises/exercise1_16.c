#include <stdio.h>
#define MAXLINE 5 /* maximum input line length */

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
   the length of arbitrary long input lines, and as much as possible of the text. */
int main()
{
        int len, c; /* current line length */
        int max = 0; /* maximum length seen so far */
        char line[MAXLINE]; /* current input line */
        char buffer[MAXLINE]; /* buffer for temp lines */
        char longest[MAXLINE]; /* longest line saved here */

        while ((len = _getline(line, MAXLINE)) > 0) {

                if (len == MAXLINE - 1 && line[len - 1] != '\n') {
                    while ((c=getchar())!=EOF && c!='\n')
                        ++len;
                    if (c == '\n')
                        ++len;
                }

                if (len > max){
                    max = len;
                    copy(longest, line);
                }
        }

        if (max > 0) /* there was a line */
                if (max >= MAXLINE)
                        printf("Len: %d; Line: [%s...]\n", max, longest);
                else
                        printf("Len: %d; Line: [%s]\n", max, longest);
        return 0;
}

/* getline: read a line into s, return length */
int _getline(char s[],int lim)
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
