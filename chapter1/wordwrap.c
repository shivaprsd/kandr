#include <stdio.h>

#define MAXWIDTH 10     /* maximum column width of lines */
#define TABSTOP  8      /* column width of a tab */

int getword(char word[]);
int printword(char word[],int length, int cp);
int expandtab(int cp);
int printblanks(char blanks, int cp);

/* fold long lines of input into multiple shorter lines */
main()
{
    int c, i, cp, len;
    char word[MAXWIDTH];    /* save input words */

for (i=0; i<MAXWIDTH; ++i) printf("%d",i); putchar('\n');
    cp = 0;             /* position of the char in the line */
    len = 0;            /* length of the next word */
    while ((len=getword(word)) > 0)
        cp = printword(word, len, cp);
    return 0;
}

int getword(char s[])
{
    int c, len;

    len = 0;
    while ((c=getchar()) != EOF)
    {
        s[len] = c;
        ++len;
        if (c == '\n' || c == '\t' || c == ' ' || len >= MAXWIDTH)
            return len;
    }
    return 0;
}

int printword(char s[], int len, int cp)
{
    int i;

    if (cp+len-1 > MAXWIDTH)
    {
        putchar('\n');
        cp = 0;
    }
    for (i = 0; i < len-1; ++i)
        putchar(s[i]);
    cp = printblanks(s[i], cp+len-1);
    return cp;
}

int expandtab(int cp)
{
    int incr, i;

    incr = TABSTOP - cp%TABSTOP;
    if (cp+incr > MAXWIDTH)
    {
        putchar('\n');
        return 0;
    }
    for (i = 0; i < incr; ++i)
        putchar(' ');
    return cp+incr;
}

int printblanks(char c, int cp)
{
    if (c == '\n')
    {
        putchar('\n');
        cp = 0;
    }
    else if (c == '\t')
        cp = expandtab(cp);
    else
    {
        if (c == ' ')
            putchar(' ');
        else
            putchar(c);
        ++cp;
    }
    return cp;
}
