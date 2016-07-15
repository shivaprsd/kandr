#include <stdio.h>

/* count blanks, tabs and newlines in input */
main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nl;
        if (c == '\t')
            ++nl;
        if (c == '\n')
            ++nl;
    }
    printf("%d\n", nl);
}
