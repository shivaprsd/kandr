#include <stdio.h>
#define MAXLENGTH 80        /* maximum string length */

void escape(char to[], char from[]);
void descape(char to[], char from[]);

/* test escape and descape functions */
main()
{
    char c, from[MAXLENGTH], to[MAXLENGTH];
    int i = 0;

    while ((c=getchar()) != EOF)
        if (i < MAXLENGTH-1)
        {
            from[i++] = c;
            if (c == '\n')
            {
                from[i] = '\0';
                escape(to, from);
                descape(from, to);
                printf("%s\n%s", to, from);
                i = 0;
            }
        }
    return 0;
}

/* escape: copy t to s, replacing escape sequences with their visible forms
 * assumes s is large enough */
void escape(char s[], char t[])
{
    int i, j;
    char c;

    for (i = j = 0; (c = t[i]) != '\0'; ++i)
        switch (c)
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
    s[j] = '\0';
}

/* de-escape: copy t to s, replacing visible forms of escape sequences with 
 * real escape characters; assumes s is large enough */
void descape(char s[], char t[])
{
    int i, j;
    char c, d;

    for (i = j = 0; (c = t[i]) != '\0'; ++i)
        if (c == '\\')
            switch (d = t[++i])
            {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case '\\':
                    s[j++] = c;
                    --i;
                    break;
                default:
                    s[j++] = c;
                    s[j++] = d;
                    break;
            }
        else
            s[j++] = c;
    s[j] = '\0';
}
