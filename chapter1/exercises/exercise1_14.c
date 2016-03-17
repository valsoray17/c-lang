#include <stdio.h>
/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input. */
void
main()
{
    int len_freq[94];
    int height = 0;

    int c, i, j;

    for(i = 0; i <= 93; ++i)
        len_freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if(33 <= c && c <= 126) {
            ++len_freq[c-33];
            if(len_freq[c-33] >= height)
                height = len_freq[c-33];
        }
    }

    for(i = height; i > 0; --i){
        printf("%4d|", i);
        for(j = 0; j <= 93; ++j){
            if(len_freq[j] >= i)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("    +");
    for(i = 0; i <= 93; ++i)
        printf("-");
    printf("\n     ");

    for(i = 0; i <= 93; ++i) {
        printf("%c", i+33);
    }
    printf("\n");
}
