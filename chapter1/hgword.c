#include <stdio.h>

#define IN 1            /* inside a word  */
#define OUT 0           /* outside a word */
#define MAXLENGTH 12    /* maximum word length */

/* draw a histogram of the lengths of words in its input
 * version 1 - horizontal bars */
main()
{
    int wl, c, i, j, state;
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
    /* draw histogram */
    printf("Length of word - occurence\n");
    for (i = 0; i < MAXLENGTH; ++i)
    {
        printf("%2d ", i+1);
        for (j = 0; j < nwords[i]; ++j)
            putchar('=');
        putchar('\n');
    }
}
