#include <stdio.h>

#define LOWER   0   /* lower limit of table */
#define UPPER   300 /* upper limit of the table */
#define STEP    20  /* iterative step of the table */

/* print Fahrenheit-Celsius table for fahr = 0, 20, .., 300 */

int main() {
    float fahr, celsius;

    fahr = LOWER;
    printf("*** Fahrenheit to Celsius ***\n\n");
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= UPPER) {
        celsius = (fahr - 32.0) * (5.0 / 9.0);
        printf("%10.1f\t%7.1f\n", fahr, celsius);

        fahr += STEP;
    }


    printf("\n\n*** Celsius to Fahrenheit ***\n\n");
    printf("Celsius\tFahrenheit\n");
    for (celsius = UPPER; celsius >= 0; celsius -= STEP) {
        printf("%7.1f\t%10.1f\n", celsius, (celsius * 1.8) + 32);
    }
}