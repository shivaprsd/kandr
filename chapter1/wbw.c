#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

/* print the input back, one word per line */
main()
{
    int c, state;

    state = OUT;    /* initially we are not in a word */

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN)
            {
                /* we're inside a word and we encountered a white space */
                state = OUT;
                putchar('\n');
            }
        }
        else
        {
            if (state == OUT)    /* it is the first character of a word */
                state = IN;
            putchar(c);
        }
    }
}
