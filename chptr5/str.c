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

#endif
