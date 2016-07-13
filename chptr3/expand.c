#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 80        /* maximum string length */

void expand(char s1[], char s2[]);

/* test expand function */
main()
{
    char c, s1[MAXLENGTH], s2[MAXLENGTH];
    int i;

    i = 0;
    while ((c=getchar()) != EOF)
        if (c == '\n' || i >= MAXLENGTH-1) 
        {
            s1[i] = '\0';
            expand(s1, s2);
            printf("%s\n", s2);
            i = 0;
        }
        else
            s1[i++] = c;
    return 0;
}

/* expand: expand shorthand notations like a-z in s1 into the equivalent
 * complete list abc...xyz in s2; assumes s2 is large enough */
void expand(char s1[], char s2[])
{
    char beg, end;      /* beginning and end of the range */
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (s1[i] == '-' && i>0 && (s1[i+1] != '\0'))
        {
            beg = s1[i-1] + 1;  /* we have already copied the char before '-' */
            end = s1[i+1] - 1;  /* copy char after '-' in the next run of for */
            /* ranges should be alphabets/digits */
            if (isalnum(beg) && isalnum(end))
                while (beg <= end)
                    s2[j++] = beg++;
        }
        else
            s2[j++] = s1[i];    /* copy other chars (including range-ends) */
    s2[j] = '\0';
}
