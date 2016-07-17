#include <stdio.h>
#include <stdlib.h>         /* for atof() */
#include <ctype.h>          /* for isdigit() */
#define MAXLINE 50          /* maximum command length */
#define MAXOP   30          /* maximum operator/operand size */
#define MAXSTACK 50         /* maximum number of operands in the line */
#define NUMBER  '0'         /* signal that a number was found */

int sp = 0;                 /* next free stack position */
double stack[MAXSTACK];
int get_line(char line[], int limit);
void calc(char line[]);

/* reverse Polish calculator */
main()
{
    char s[MAXLINE];
    double opr;

    printf("calc> ");
    while (get_line(s, MAXLINE) > 0)
    {
        calc(s);
        printf("calc> ");
    }
    putchar('\n');
    return 0;
}

/* get_line: read atmost lim chars into s[]; returns the length of the line */
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

/* calc: calculate and print the result of the command in s */
void calc(char s[])
{
    int i, j, opr;
    char c, opd[MAXOP];
    double operate(char operator, char operand[]);
    
    i = j = 0;
    opr = -1;
    while ((c = s[i]) != '\n')
    { 
        if (c == ' ' || c == '\t')
            i++;
        else if (c == '-' && isdigit(s[i+1]))
        {
            opd[j++] = '-';         /* negative number */
            i++;
        }
        else
        {
            if (isdigit(c))
            {
                do
                {
                    opd[j++] = c;
                }
                while (isdigit(c = s[++i]));
                if (c == '.')
                    do
                    {
                        opd[j++] = c;
                    }
                    while (isdigit(c = s[++i]));
                opd[j] = '\0';
                j = 0;
                opr = NUMBER;
            }
            else
            {
                opr = c;
                i++;
            }
            operate(opr, opd);
        }
    }
    if (opr != -1)              /* some operation was performed */
        printf("\t= %.8g\n", operate('\n', opd));
}

/* operate: perform operation opr on opd and manipulate stack */
double operate(char opr, char opd[])
{
    double  op2;
    void    push(double item);
    double  pop(void);

    switch (opr)
    {
        case NUMBER:
            push(atof(opd));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();        /* right-hand side operand */
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 == 0.0)
                printf("error: division by 0\n");
            else
                push(pop() / op2);
            break;
        case '\n':
            return pop();
        case 'q':
            printf("(press Ctr+D to quit)\n");
            break;
        default:
            printf("error: unknown command %c\n", opr);
            break;
    }
    return 0.0;
}

/* push: push f onto stack */
void push(double f)
{
    if (sp < MAXSTACK)
        stack[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return the top element from the stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
