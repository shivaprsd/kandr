#include <stdio.h>
#define MAXLENGTH 150       /* maximum line length */

int get_line(char line[], int maxlength);

/* remove trailing blanks from each line, and delete entirely blank lines */
main()
{
    int len;                /* length of the current line */
    char line[MAXLENGTH];   /* current line being read */
    int c;

    /* read individual lines */
    while ((len = get_line(line, MAXLENGTH)) > 0)
    {
        if (len==MAXLENGTH-1 && line[MAXLENGTH-2]!='\n')
            line[MAXLENGTH-2] = '\n';
        /* trim the trailing blanks */
        while ((c = line[len-2]) == '\n' || c == '\t' || c == ' ')
            --len;
        line[len-1] = '\n';
        line[len]   = '\0';
        if (len > 1)        /* ignore completely blank lines */
            printf("%3d %s", len, line);
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
