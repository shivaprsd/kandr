#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

/* atof extended to process scientific notation */
main()
{
    double sum, atof(char s[]);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0.0;
    while (get_line(line, MAXLINE) > 0)
        printf("=\t%g +\n", sum += atof(line));
    return 0;
}

/* get_line: get line int s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof: convert string s to double; extended to handle scientific notation */
double atof(char s[])
{
    double val, dec, epow;
    int i, e, sign, esign;

    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (dec = 10.0; isdigit(s[i]); i++)
    {
        val = val + (s[i] - '0') / dec;
        dec *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')     /* exponential part */
    {
        esign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (e = 0; isdigit(s[i]); i++)
            e = e * 10 + (s[i] - '0');
        epow = 1.0;         /* decimal power */
        while (e-- > 0)
            epow *= 10.0;
        epow = (esign == -1) ? 1/epow : epow;   /* +ve or -ve exponent? */
    }
    return val * epow;
}
