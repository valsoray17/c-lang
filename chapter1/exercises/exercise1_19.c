#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int _getline(char line[], int maxline);
void _reverse(char s[], int len);

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */
int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = _getline(line, MAXLINE)) > 0){
        _reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

void _reverse(char s[], int len)
{
    char tmp;
    if (s[len - 1] == '\n')
        len--;
    for (int i = 0; i < len / 2; i++){
        tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

/* getline: read a line into s, return length */
int _getline(char s[], int lim)
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
