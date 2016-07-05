#include <stdio.h>

#define MAXCHAR 128         /* number of ASCII characters */

/* draw a histogram of the frequencies of
 * different characters in the input    */
main()
{
    int c, i, j;
    int nchars[MAXCHAR];    /* count the frequency of each char */

    for (i = 0; i < MAXCHAR; ++i)
        nchars[i] = 0;

    while ((c = getchar()) != EOF)
        ++nchars[c];
    /* draw histogram */
    printf("character - frequency\n");
    for (i = 32; i < MAXCHAR; ++i)  /* most characters before 32 are non-printable */
    {
        putchar(i);
        for (j = 0; j < nchars[i]; ++j)
            putchar('=');
        putchar('\n');
    }
}
