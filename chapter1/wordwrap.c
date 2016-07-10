#include <stdio.h>

#define MAXWIDTH 20     /* maximum column size of lines */
#define TABSTOP  8      /* column size of a tab */

int getword(char word[]);
int printword(char word[],int length, int cp);
int printblank(char blank, int cp);
int expandtab(int cp);

/* fold long lines of input into multiple shorter lines */
main()
{
    int c, cp, len;
    char word[MAXWIDTH];    /* save input words */

    cp = 0;             /* position of the char in the line */
    len = 0;            /* length of the next word */
    while ((len=getword(word)) > 0)
        cp = printword(word, len, cp);
    return 0;
}

/* getword: read a single word into s and return it's length
 * if the word is longer than column size then it's wrapped mid-word */
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

/* printword: print a word considering its length and cursor position;
 * returns the new cursor position after printing */
int printword(char s[], int len, int cp)
{
    int i;

    if (len > 1)        /* word contains atleast one non-blank character */
    {
        /* len-1 instead of len for ignoring the last char
         * which is processed seperately using printblank */
        if (cp+len-1 > MAXWIDTH)
        {
            putchar('\n');  /* wrap word if it overflows column size */
            cp = 0;
        }
        for (i = 0; i < len-1; ++i, ++cp)   /* print the word */
            putchar(s[i]);
    }
    cp = printblank(s[len-1], cp);
    return cp;
}

/* printblank: print the blank character considering the cursor position
 * also handles non-blank characters of words that are wrapped mid-word;
 * returns the new cursor position after printing */
int printblank(char c, int cp)
{
    if (c == '\n')
    {
        putchar('\n');
        cp = 0;
    }
    else if (c == '\t')
        cp = expandtab(cp);
    else if (c == ' ' && cp >= MAXWIDTH)    /* if no room for blank spaces, */ 
        ;                                   /* do nothing! ignore it. */
    else        /* it is either a space that has room, or a mid-word char */
    {
        putchar(c);
        ++cp;
    }
    return cp;
}

/* expandtab: expand a tab to the next TABSTOP or column-end (whichever comes
 * first); return the new cursor position after printing */
int expandtab(int cp)
{
    int incr;

    incr = TABSTOP - cp%TABSTOP;    /* spaces needed to reach next TABSTOP */
    if (cp+incr > MAXWIDTH)         /* end of the column comes first */
        incr = MAXWIDTH - cp;
    /* expand the tab into spaces */
    while (incr)
    {
        putchar(' ');
        ++cp;
        --incr;
    }
    return cp;
}
