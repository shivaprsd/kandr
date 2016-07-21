#include <stdio.h>
#define TABSTOP 8       /* default tab size in spaces */
#define BEG     0       /* default beginning column */

/* replace tabs with proper number of blanks spaces */
main(int argc, char *argv[])
{
    int c, pos, incr, flag;
    int tab, beg;            /* user-specified tab size and beginning column */

    flag = 0;
    tab = beg = 0;
    if (argc > 1)
    {
        if (argc == 3 && **++argv == '-' && **(argv+1) == '+')
        {
            while ((c = *++argv[0]) && isdigit(c))
                    beg = beg*10 + c-'0';
            if (c != '\0' || *(argv[0]-1) == '-')
                flag = 1;
            argv++;
            while ((c = *++argv[0]) && isdigit(c))
                    tab = tab*10 + c-'0';
            if (c != '\0' || *(argv[0]-1) == '+')
                flag = 1;
        }
        else
            flag = 1;
    }
    else
    {
        tab = TABSTOP;
        beg = BEG;
    }
    if (flag)
    {
        printf("Usage: detab [-m +n]\n\ttabstops every n columns, \
starting at column m (both optional)\n");
        return -1;
    }
    pos = 0;            /* position of character in the current line */
    while ((c = getchar()) != EOF)
        if (c == '\t')
        {
            /* number of spaces to be printed (see end for explanation) */
            incr = tab - (pos-beg)%tab;

            while (incr)
            {
                putchar(' ');
                ++pos;
                --incr;
            }
        }
        else
        {
            putchar(c);
            if (c == '\n')
                pos = 0;    /* advance to the beginning of the new line */
            else
                ++pos;
        }
    return 0;
}

/* calculating the number of spaces to print to reach the next tab stop:
 *
 * pos % TABSTOP gives the number of characters already printed within
 * the tabstop; subtracting this value from TABSTOP gives the number of
 * spaces to be printed to complete the TABSTOP. 
 *
 * yeah, pretty obvious :)
 */
