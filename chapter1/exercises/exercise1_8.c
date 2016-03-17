#include <stdio.h>
/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
void
main()
{
    int c, bl = 0, tabs = 0, nl = 0;
    
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++bl;
        else if (c == '\t')
            ++tabs;
    printf("blanks: %d, tabs: %d, newlines: %d\n", bl, tabs, nl);
}