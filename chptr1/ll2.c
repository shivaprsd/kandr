#include <stdio.h>
#define MAXLENGTH 150       /* maximum line length */
#define PRINTLEN  80        /* print lines longer than this limit */

int get_line(char line[], int maxlength);

/* print all input lines longer than PRINTLEN characters */
main()
{
    int len;                /* length of the current line */
    char line[MAXLENGTH];   /* current line being read */

    while ((len = get_line(line, MAXLENGTH)) > 0)
    {
        if (len==MAXLENGTH-1 && line[MAXLENGTH-2]!='\n')
            line[MAXLENGTH-2] = '\n';
        if (len > PRINTLEN)
            printf("%d %s", len, line);
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
