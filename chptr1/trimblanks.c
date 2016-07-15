#include <stdio.h>

/* replace each string of one or more blanks by a single blank */
main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')           /* if the character is a space */
        {
            putchar(c);         /* print it */
            while (c == ' ')    /* skip the rest of the spaces, if any */
                c = getchar();
        }
        putchar(c);             /* print the non-spaces */
    }
}
