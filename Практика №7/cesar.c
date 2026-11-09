#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
/* Могут пригодиться функции: strlen, strcmp, strchr, strtok, toupper,
tolower, isalpha, isdigit, isspace. */


char move(char _c, int _shift){
    if (_c >= 'A' && _c <= 'Z'){
        int loc = _c + _shift;
        if (loc > 'Z') loc -= 26;
        return loc;
    }
    if (_c >= 'a' && _c <= 'z'){
        int loc = _c + _shift;
        if (loc > 'z') loc -= 26;
        return loc;
    }
    return _c;
}
void hack(const char *text){
    char texts[26][255];
    int maxid = 0;
    int maxcnt = -1;

    for (int shift = 0; shift < 26; shift++){
        int cnt = 0;
        int i;
        for (i = 0; text[i] != '\0' && i < 254; i++){
            char c = move(text[i], shift);
            texts[shift][i] = c;
            if (tolower((unsigned char)c) == 'e' || tolower((unsigned char)c) == 't') cnt++;
        }
        texts[shift][i] = '\0';

        if (cnt > maxcnt){
            maxcnt = cnt;
            maxid = shift;
        }
    }
    printf("\nВзлом (сдвиг %d): %s\n", maxid, texts[maxid]);
}

int main() {
    char buffer[255], b_shifted[255];
    int shift;

    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    printf("Enter shift: ");
    scanf("%d", &shift);
    shift = ((shift % 26) + 26) % 26;

    int len = strlen(buffer);
    for (int i = 0; i < len; i++)
        b_shifted[i] = move(buffer[i], shift);
    b_shifted[len] = '\0';


    printf("Result: %s\n", b_shifted);
        hack(buffer);
    return 0;
}