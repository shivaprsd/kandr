#include <stdio.h>
#include "str.c"
#include "math.c"

/* test functions written in the chapter */
main()
{
    char s1[15] = "hello, ";
    char s2[] = "world!";
    int len = 0;
    /* str_cat */
    str_cat(s1, s2);
    printf("%s\n", s1);
    /* str_end */
    if (str_end(s1, s2))
        printf("%s found at the end of %s\n", s2, s1);
    else
        printf("%s is not at the end of %s\n", s2, s1);
    /* str_ncpy */
    str_ncpy(s1, s2, 3);
    printf("after copying: %s\n", s1);
    /* str_ncat */
    str_ncat(s1, s2, 5);
    printf("after concatenation: %s\n", s1);
    /* str_ncmp */
    printf("to the first %d chars, s1 - s2 = %d\n", 4, str_ncmp(s1, s2, 4));
    /* get_line */
    len = get_line(s1, 15);
    printf("%d %s", len, s1);
    /* math: itoa */
    itoa(len, s1, 4);
    printf("in strings: %s\n", s1); 
    return 0;
}
