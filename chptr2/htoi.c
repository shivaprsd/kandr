#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 16      /* maximum hexadecimal digits */

int htoi(const char hex[]);

/* test htoi: string hexadecimal to integer conversion */
main()
{
    int c, i;
    char hex[MAXSIZE+1];

    i = 0;
    while ((c=getchar()) != EOF)
    {
        if (i == MAXSIZE || c == '\n')
        {
            hex[i] = '\0';
            printf("%d\n", htoi(hex));
            i = 0;
        }
        else
        {
            hex[i] = c;
            ++i;
        }
    }
    return 0;
}

/* htoi: convert a string of hexadecimal digits to equivalent integer
 * automatically ignores optional 0x/0X prefix and invalid digits */
int htoi(const char s[])
{
    int i, n;
    char c;
    
    for (i = 0, n = 0; s[i] != '\0'; ++i)
    {
        c = tolower(s[i]);
        if (isdigit(c))
            n = n*16 + (c-'0');
        else if (c >= 'a' && c <= 'f')
            n = n*16 + (10 + c-'a');    /* a = 10, b = 11 = 10+1, etc. */
    }
    return n;
}
