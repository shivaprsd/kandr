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

/* reverse: reverse the character string s; recursive version */
void reverse(char s[])
{
    static int len = 0;     /* find the length, once per string */
    static int i = 0;       /* array index */
    char temp;

    /* find the length of the string */
    if (len == 0)
    {
        for (; s[len] != '\0'; ++len)
            ;
        if (s[len-1] == '\n')   /* if the last character is newline, */
            --len;              /* leave it in place */
    }
    /* reverse s */
    if (i < len/2)
    {
        /* swap, increment the index and call the next level */
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
        i++;
        reverse(s);
    }
    else
        /* a string has been reversed, reset static objects for the next call */
        i = len = 0;
}
