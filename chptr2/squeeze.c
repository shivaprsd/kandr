#include <stdio.h>
#define MAXLENGTH 15        /* maximum length of strings */

void squeeze(char s1[], char s2[]);
int get_line(char line[], int limit);

/* test squeeze function */
main()
{
    char c, s1[MAXLENGTH], s2[MAXLENGTH];

    printf("squeeze the letters: ");
    get_line(s2, MAXLENGTH);
    printf("out of the string:   ");
    get_line(s1, MAXLENGTH);
    squeeze(s1, s2);
    printf("squeezing... done!   %s\n", s1);
    return 0;
}

/* get_line: read atmost lim characters into s[] *
 * and return the length of the line */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';        /* terminate the string */
    return i;
}

/* squeeze: delete all characters in s2 from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; ++k)
    {
        for (i = j = 0; s1[i] != '\0'; ++i)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}
