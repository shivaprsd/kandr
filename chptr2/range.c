#include <stdio.h>

main()
{
    unsigned char   uc;
    unsigned short  us;
    unsigned int    ui;
    unsigned long   ul;

    uc = us = ui = ul = 0;
    /* unsigned int's */
    printf("unsigned char:\t %u ", uc);
    printf("to %u\n", --uc);
    printf("unsigned short:\t %u ", us);
    printf("to %u\n", --us);
    printf("unsigned int:\t %u ", ui);
    printf("to %u\n", --ui);
    printf("unsigned long:\t %lu ", ul);
    printf("to %lu\n", --ul);
    /* signed int's */
    printf("signed char:\t-%u to +%u\n", uc/2 + 1, uc/2); 
    printf("signed short:\t-%u to +%u\n", us/2 + 1, us/2); 
    printf("signed int:\t-%u to +%u\n", ui/2 + 1, ui/2); 
    printf("signed long:\t-%lu to +%lu\n", ul/2 + 1, ul/2); 
    return 0;
}
