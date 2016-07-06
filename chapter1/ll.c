#include <stdio.h>
#define MAXLENGTH 1000      /* maximum line length */

int get_line(char line[], int maxlength);
void copy(char to[], char from[]);

/* print the longest line from the input */
main()
{
    int len;                /* length of the current line */
    int max;                /* length of the longest line */
    char line[MAXLENGTH];       /* current line being read */
    char longest[MAXLENGTH];    /* longest line */

    max = 0;
    while ((len = get_line(line, MAXLENGTH)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)            /* a line was read */
        printf("%s", longest);
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
    /*s[i] = '\0';        /* terminate the string */
    return i;
}

/* copy: copy from[] to to[]; assuming to[] is large enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
