#include <stdio.h>

int main() {
    short check = 0;
    int key[128] = {0};
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z')
            key[ch - 'A' + 'a'] = 1;
        key[ch] = 1;
    }
    if (key['+'])
        for (int i = 'A'; i <= 'Z'; i++)
            key[i] = 1;

    while ((ch = getchar()) != '\n') {
        if (key[ch])continue;
        printf("%c", ch);
        check = 1;
    }
    if(check == 0)
        printf("\n");
    return 0;
}