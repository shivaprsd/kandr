#include <stdio.h>

float tocelcius(float fahr);

/* print Fahrenheit-Celsius table
 * using the tocelsius function */
main()
{
    float fahr;
    int lower, upper, step;

    lower   = 0;        /* lower limit of temperature table */
    upper   = 300;      /* upper limit */
    step    = 20;       /* step size */

    fahr = lower;
    while (fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, tocelcius(fahr));
        fahr = fahr + step;
    }
    return 0;
}

/* tocelcius:   convert fahr to celcius */
float tocelcius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
