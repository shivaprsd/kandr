#ifndef STR
#define STR

/* str_cat: concatenate t to end of s; assumes s is big enough */
void str_cat(char *s, char *t)
{
    while (*s)        /* find end of s */
        s++;
    while ((*s++ = *t++))
        ;
}

#endif
