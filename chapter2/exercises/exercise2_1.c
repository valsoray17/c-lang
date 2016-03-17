#include <stdio.h>
#include <limits.h>
/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
   variables, both signed and unsigned, by printing appropriate values from standard headers
   and by direct computation. Harder if you compute them: determine the ranges of the various
   floating-point types. */
void
main()
{
        printf("Unsigned char: 0 - %d\nSigned char: %d - %d\nUnsigned short: 0 - %d\n"
                "Signed short: %d - %d\nUnsigned int: 0 - %u\nSigned int: %d - %d\n"
                "Unsigned long: 0 - %lu\nSigned long: %ld - %ld\n", UCHAR_MAX, SCHAR_MIN, SCHAR_MAX,
               USHRT_MAX, SHRT_MIN, SHRT_MAX, UINT_MAX, INT_MIN, INT_MAX,
               ULONG_MAX, LONG_MIN, LONG_MAX);
}
