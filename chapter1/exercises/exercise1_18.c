#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TRUE 1
#define FALSE 0

int getline1(char line[], int maxline);
int remove_trailing(char s[], int len);

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */
int
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    
    max = 0;
    while ((len = getline1(line, MAXLINE)) > 0)
        if ((len = remove_trailing(line, len)) > 0 && line[0] != '\n') {
            printf("%s", line);
        }
    return 0;
}

int
remove_trailing(char s[], int len)
{
    int newline = FALSE;
    if (len > 0 && s[len - 1] == '\n') {
        newline = TRUE;
        len--;
    }
    
    while (len > 0 && s[len - 1] == '\t' || s[len - 1] == ' ')
        len--;
    if (newline)
        s[len++] = '\n';
    
    s[len] = '\0';
    return len;
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