#include <stdio.h>
#ifndef STR
#define STR

/* str_cat: concatenate t to end of s; assumes s is big enough */
void str_cat(char *s, char *t)
{
    while (*s)          /* find end of s */
        s++;
    while ((*s++ = *t++))
        ;
}

/* str_end: return 1 if t occurs at the end of s, 0 otherwise */
int str_end(char *s, char *t)
{
    char *d = t;        /* remember the beginning of t */

    while (*s)          /* find end of s */
        s++;
    while (*t++)        /* move back s as many times as there are chars in t */
        s--;
    while (*d++ == *s++)    /* compare d (i.e. t) with the end of s */
        if (!*d)            /* *d is \0, reached end of d */
            return 1;
    return 0;
}

/* str_ncpy: copy atmost n chars from t to s */
void str_ncpy(char *s, char *t, int n)
{
    while (n-- > 0 && (*s++ = *t++))
        ;
    if (n <= 0)         /* we met an early exit from the loop */
        *s = '\0';
}

/* str_ncat: concatenate atmost n chars from t at the end of s */
void str_ncat(char *s, char *t, int n)
{
    while (*s)          /* find end of s */
        s++;
    while (n-- > 0 && (*s++ = *t++))
        ;
    if (n <= 0)
        *s = '\0';
}

/* str_ncmp: compare atmost n chars in s & t; returns lexicographical diff */
int str_ncmp(char *s, char *t, int n)
{
    while (*s == *t)
    {
        if (*s == '\0' || --n <= 0)     /* we compare the chars at the top */
            return 0;
        s++, t++;
    }
    return *s - *t;
}

/* get_line: read atmost lim chars into s; return length */
int get_line(char *s, int lim)
{
    int c;
    char *t;

    t = s;              /* save the beginning of the string */
    while (lim-- > 1 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';          /* terminate the string */
    return s - t;
}

#endif
