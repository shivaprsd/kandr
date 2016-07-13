#include <stdio.h>
#define MAXLENGTH 80

void itob(int number, char str[], int base);

/* test the itob function */
main()
{
    int n, b;
    char s[MAXLENGTH];

    printf("convert integer: ");
    scanf("%d", &n);
    printf("to the base of : ");
    scanf("%d", &b);
    itob(n, s, b);
    printf("%s\n", s);
    return 0;
}

/* itob: convert decimal n to base b number as a character string s */
void itob(int n, char s[], int b)
{
    int i, d, sign;
    void reverse(char s[]);

    i = 0;
    sign = n;                   /* store sign */
    do                          /* generate digits in reverse order */
    {
        /* get next digit: absolute value of n % b */
        d = ((d = n%b) < 0) ? -d : d;
        s[i++] = (d < 10) ? '0'+d : 'a'+d-10;
    } while ((n /= b) != 0);   /* quotient becomes the new dividend */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse the character string s */
void reverse(char s[])
{
    int i, len;
    char temp;

    /* find the length of the string */
    for (len = 0; s[len] != '\0'; ++len)
        ;
    if (s[len-1] == '\n')   /* if the last character is newline, */
        --len;              /* leave it in place */
    /* reverse s */
    for (i = 0; i < len/2; ++i)
    {
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}
