#ifndef MATH
#define MATH

/* itoa: convert decimal n to character string s, fixed width of fw */
void itoa(int n, char *s, int fw)
{
    int d, sign, len;
    char c, *t;

    t = s;              /* store the beginning of s */
    sign = n;           /* store sign */
    do                  /* generate digits in reverse order */
    {
        /* get next digit: absolute value of n % 10 */
        d = ((d = n%10) < 0) ? -d : d;
        *s++ = '0' + d;
    } while (n /= 10);      /* quotient becomes the new dividend */
    if (sign < 0)
        *s++ = '-';
    len = s - t;
    while (len++ < fw)      /* pad with blanks to make it fill fw */
        *s++ = ' ';
    *s-- = '\0';
    while (--fw/2 > 0)      /* reverse s */
    {
        c = *t;
        *t++ = *s;
        *s-- = c;
    }
}

#endif
