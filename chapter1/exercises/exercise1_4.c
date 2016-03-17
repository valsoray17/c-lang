#include <stdio.h>
/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
void
main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = -40; /* lower limit of temperature scale */
    upper = 150; /* upper limit */
    step = 10;/* step size */

    celsius = lower;

    printf("Celsius\tFahernheit\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%7.0f\t%10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
