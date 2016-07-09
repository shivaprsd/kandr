#include <stdio.h>

#define IN  1       /* inside quotes/comments */
#define OUT 0       /* outside quotes/comments */

/* remove all (multi-line comments) from a C program */
main()
{
    int c, d, qt, cmt;

    qt = cmt = OUT;
    while ((c=getchar()) != EOF)
    {
        if (c == '/' && qt == OUT && cmt == OUT)
        {
            d = getchar();
            if (d == '*')
                cmt = IN;
            else
            {
                putchar(c);
                putchar(d);
            }
        }
        else if (c == '*' && qt == OUT && cmt == IN)
        {
           d = getchar();
           if (d == '/')
               cmt = OUT;
        }
        else if (c == '\"' && cmt == OUT)
        {
            if (qt == IN)
                qt = OUT;
            else
                qt = IN;
            putchar(c);
        }
        else if (cmt == OUT)
            putchar(c);
    }
    return 0;
}
