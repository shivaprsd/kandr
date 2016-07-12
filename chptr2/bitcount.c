#include <stdio.h>

int bitcount(unsigned x);

main()
{
    printf("%d\n", bitcount(42));   /* should print 3 */
    return 0;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x-1)
        ++b;
    return b;
}
