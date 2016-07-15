#include <stdio.h>
#define MAXLENGTH 150       /* maximum line length */

int get_line(char line[], int maxlength);
void reverse(char string[]);

/* reverse the input one line at a time */
main()
{
    int len;                /* length of the line */
    char line[MAXLENGTH];   /* save the line being read */

    /* read individual lines */
    while ((len = get_line(line, MAXLENGTH)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* get_line: read atmost lim characters into s[] *
 * and return the length of the line */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';        /* terminate the string */
    return i;
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
