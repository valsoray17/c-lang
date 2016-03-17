#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* Exercise 1-12. Write a program that prints its input one word per line. */
void
main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN){
                state = OUT;
                putchar('\n');
            }
        }
        else {
            state = IN;
            putchar(c);
        }
    }
}
