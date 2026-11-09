#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* Могут пригодиться функции: strlen, strcmp, strchr, strtok, toupper,
tolower, isalpha, isdigit, isspace. */

/* Функции. Сжатие серий, распаковка, сравнение строк. */

char s[] = "aaagggaaabb";

char *writeto(char *cmpr, char prev, int cnt)
{
    *cmpr = prev;
    cmpr++;
    cmpr += sprintf(cmpr, "%d", cnt);
    return cmpr;
}

char *compress()
{
    int len = strlen(s);
    char *cmpr = malloc(2 * len + 1);
    char *orig = cmpr;
    int cnt = 1;
    char prev = '\0';
    for (int c = 0; c < len + 1; c++)
    {
        if (c == len)
        {
            cmpr = writeto(cmpr, prev,cnt);
        }
        else
        {
            if (prev == s[c])
                cnt += 1;
            else if (c > 0)
            {
                cmpr = writeto(cmpr, prev,cnt);
                cnt = 1;
            }
        }
        prev = s[c];
    }
    *cmpr = '\0';
    return orig;
}

char *decompress(char *ptr, int len)
{
    int cnt = 0;
    char *text = calloc(1,sizeof(char));
    char *end = ptr + len;
    while (ptr < end){
        char target = *ptr;
        int n = 0;
        ptr += 1;
        while (ptr < end && isdigit(*ptr)){
            n = n*10 + (*ptr - '0');
            ptr++;
        }
        
        text = realloc(text, cnt + sizeof(char)*n + 1);
        for (int j = 0; j<n;j++){
            *(cnt + j+text) = target;
        }
        cnt += n;
    }
    *(text+cnt) = '\0';
    return text;
}

int compare(const char *a, const char *b)  
{
    return strcmp(a, b) == 0;
}

int main()
{
    char *res = compress();
    printf("сжато:   %s\n", res);

    char *rev = decompress(res, strlen(res));  
    printf("обратно: %s\n", rev);
    printf("%s\n", compare(s, rev) ? "равны" : "НЕ равны");

    free(res);
    free(rev);
    return 0;
}