#include <stdio.h>

#define IN 1            /* inside a word  */
#define OUT 0           /* outside a word */
#define MAXLENGTH 12    /* maximum word length */

/* draw a histogram of the lengths of words in its input
 * version 2 - vertical bars */
main()
{
    int wl, bl, c, i, j, state;
    int nwords[MAXLENGTH];

    state = OUT;            /* initially we are not in a word */
    wl = 0;                 /* count the length of each word  */
    for (i = 0; i < MAXLENGTH; ++i)
        nwords[i] = 0;

    /* count number of words of each length */
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN)
            {
                /* reached the end of a word */
                state = OUT;
                if (wl > 0 && wl <= MAXLENGTH)
                    ++nwords[wl-1]; /* indices start from 0 */
                wl = 0;
            }
        }
        else
        {
            if (state == OUT)
                state = IN; /* it is the beginning of a new word */
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                ++wl;
        }
    }
    /* find the length of the largest bar */
    for (i = 0, bl = 0; i < MAXLENGTH; ++i)
        if (bl < nwords[i])
            bl = nwords[i];

    /* draw histogram */
    for (i = bl; i >= 0 ; --i)      /* largest bars are drawn first */
    {
        for (j = 0; j < MAXLENGTH; ++j)
        {
            if (i == 0)             /* last row, print bar lables */
                printf("%2d", j+1);
            else if (nwords[j] >= i)
                printf(" X");
            else
                printf("  ");
            printf("  ");           /* spacing between bars */
        }
        putchar('\n');
    }
    printf("Lengths of the words\n");
}
