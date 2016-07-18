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
    /* str_end */
    if (str_end(s1, s2))
        printf("%s found at the end of %s\n", s2, s1);
    else
        printf("%s is not at the end of %s\n", s2, s1);
    return 0;
}
