#include <stdio.h>
#define MAXLENGTH 80

void itoa(int number, char str[], int field_width);
void itoa_r(int number, char str[]);

/* test the itoa_r function */
main()
{
    int n, fw;
    char s[MAXLENGTH];

    printf("convert integer to string: ");
    scanf("%d", &n);
    /* printf("filling a field width of : ");
    scanf("%d", &fw); */
    itoa_r(n, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert decimal n to character string s, padded to fill fw columns */
void itoa(int n, char s[], int fw)
{
    int i, d, sign;
    void reverse(char s[]);

    i = 0;
    sign = n;                   /* store sign */
    do                          /* generate digits in reverse order */
    {
        /* get next digit: absolute value of n % 10 */
        d = ((d = n%10) < 0) ? -d : d;
        s[i++] = '0' + d;
    } while ((n /= 10) != 0);   /* quotient becomes the new dividend */
    if (sign < 0)
        s[i++] = '-';
    while (i < fw)              /* pad with blanks to make it fill fw */
        s[i++] = ' ';
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

/* itoa_r: recursive version of itoa; does not use reverse */
void itoa_r(int n, char s[])
{
    static int i = 0;   /* array index */
    int d;
    
    if (n/10 != 0)
        itoa_r(n/10, s);
    else
        if (n < 0)
            s[i++] = '-';
    d = n%10;
    s[i++] = ((d < 0) ? -d : d) + '0';
    s[i] = '\0';        /* each level except the first called overwrites this */
}
