#include <stdio.h>
#include "str.c"

/* test functions written in the chapter */
main()
{
    /* str_cat */
    char s1[15] = "hello, ";
    char s2[] = "world!";
    str_cat(s1, s2);
    printf("%s\n", s1);
    return 0;
}
