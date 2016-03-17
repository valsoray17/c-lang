#include <stdio.h>

void
count_1()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}

void
count_2()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

/* count characters in input; 1st version */
void
main()
{
    count_2();
}
