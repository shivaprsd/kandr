#include <stdio.h>
#include <string.h>
#define MAXLENGTH 80        /* maximum length of the strings */

int any(const char s1[], const char s2[]);
int get_line(char line[], int limit);

/* test any function */
main()
{
    char s1[MAXLENGTH], s2[MAXLENGTH];
    int i;

    printf("find any of the letters: ");
    get_line(s2, MAXLENGTH);
    printf("in the string: ");
    get_line(s1, MAXLENGTH);
    i = any(s1, s2);
    if (i == -1)
        printf("not found!\n");
    else
        printf("'%c' found at position %d\n", s1[i], i+1);
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

/* any: return the first-most location of any character from s2 in s1
 * return -1 if no match found */
int any(const char s1[], const char s2[])
{
    int i, j;
    int index, len;

    index = len = strlen(s1);
    for (j = 0; s2[j] != '\0'; ++j)
        for (i = 0; s1[i] != '\0'; ++i)
            if (s1[i] == s2[j] && s1[i] != '\n' && index > i)
                index = i;
    if (index == len)       /* index not changed => no match found */
        return -1;
    else
        return index;
}
