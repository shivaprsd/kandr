#include <stdio.h>

#define TABSTOP 8       /* tab size in spaces */

/* replace blanks with minimal number of tabs and spaces */
main()
{
    int c, pos, incr, blanks;

    pos = 0;            /* position of character in the current line */
    blanks = 0;         /* number of continuous blanks */
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++blanks;
        else
        {
            /* incr: spaces required to reach the next tabstop (see end) */
            while (blanks >= (incr = TABSTOP-pos%TABSTOP))
            {
                putchar('\t');
                pos = pos + incr;
                blanks = blanks - incr;
            }
            while (blanks)  /* only spaces left now */
            {
                putchar(' ');
                ++pos;
                --blanks;
            }
            putchar(c);     /* print the non-blank character */
            if (c == '\n')
                pos = 0;    /* advance to the beginning of the new line */
            else
                ++pos;
        }
    return 0;
}
/* calculating the number of spaces to reach the next tabstop:
 *
 * pos % TABSTOP gives the number of characters already printed within
 * the tabstop; subtracting this value from TABSTOP gives the number of
 * spaces to be printed to complete the TABSTOP. 
 *
 * yeah, pretty obvious :)
 */
