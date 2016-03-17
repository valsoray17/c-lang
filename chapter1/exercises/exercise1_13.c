#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_WORD_LENGTH 10

void
print_horizontal(int words[]){
    printf("length\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%6d: ", i + 1);
        for (int j = 0; j < words[i]; j++)
            putchar('-');
        putchar('\n');
    }
}

void
print_vertical(int words[]){
    int diagram_height = 0;

    printf(" count| ");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%d ", i + 1);
        if (words[i] > diagram_height)
            diagram_height = words[i];
    }
    putchar('\n');
    printf("------+");
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
        printf("--");
    putchar('\n');

    for (int i = diagram_height; i > 0; i--){
        printf("%6d| ", i);
        for (int j = 0; j < MAX_WORD_LENGTH; j++)
            if (words[j] >= i)
                printf("# ");
            else
                printf("  ");
        putchar('\n');
    }
    putchar('\n');
}

/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
void
main()
{
    int c, state, current_word_len = 0;
    state = OUT;

    int words_len[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        words_len[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN && current_word_len > 0 && current_word_len < MAX_WORD_LENGTH) {
                ++words_len[current_word_len - 1];
            }
            state = OUT;
            current_word_len = 0;
        }
        else {
            if (state == OUT)
                state = IN;
            ++current_word_len;
        }
    }

    print_horizontal(words_len);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    print_vertical(words_len);
}
