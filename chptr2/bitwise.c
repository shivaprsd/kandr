#include <stdio.h>

int setbits(int, int, int, int);
int invert(int, int, int);
int rightrot(int, int);

main()
{
    int x = 42;       /* 00101010 */
    int y = 7;        /* 00000111 */
    int z = 234;

    printf("%u\n", setbits(x, 5, 3, y));
    printf("%u\n", invert(y, 7, 5));
    printf("%u\n", rightrot(z, 31));
    return 0;
}

int setbits(int x, int p, int n, int y)
{
    int MASK = ~(~0 << n);
    return (x & ~(MASK << (p+1-n))) | ((MASK & y) << (p+1-n));
}

int invert(int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}

int rightrot(int x, int n)
{
    while(n--)
        if (x & 1)
            x = (x >> 1) | ~(~0u >> 1);
        else
            x = (x >> 1) & (~0u >> 1);
    return x;
}
