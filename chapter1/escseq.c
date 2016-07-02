#include <stdio.h>

/* copy input into output, replacing each tab,
 * backspace and backslash by visibles chars */
main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        while (c == '\t')
        {
            printf("\\t");      /* '\\' prints a single '\' */
            c = getchar();      /* move on to the next char */
        }
        while (c == '\b')
        {
            printf("\\b");
            c = getchar();
        }
        while (c == '\\')
        {
            printf("\\\\");
            c = getchar();
        }
        putchar(c);             /* print other characters */
    }
}
