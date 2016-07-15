#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* count lines, words and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;    /* initially we are not in a word */
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;       /* we've read a character */

        if (c == '\n')
            ++nl;
        if (c == '\n' || c == '\t' || c == ' ')
            state = OUT;
        else if (state == OUT)   /* encountered the first letter of a word */
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
