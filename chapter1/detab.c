#include <stdio.h>

#define TABSTOP 8       /* tab size in spaces */

/* replace tabs with proper number of blanks spaces */
main()
{
    int c, pos, incr;

    pos = 0;            /* position of character in the current line */
    while ((c = getchar()) != EOF)
        if (c == '\t')
        {
            /* number of spaces to be printed (see end for explanation) */
            incr = TABSTOP - (pos%TABSTOP);

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
