#include <cstdio>
#include <cstring>

bool isH(char *s){
    for(int i = 0; i < strlen(s); ++i){
        if(s[i] != s[strlen(s)-1-i])
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char s[1005], p[1005];
    scanf("%s", s);
    for(int i = 0; i < strlen(s)/2; ++i){
        int tmp = s[i];
        s[i] = s[strlen(s)-i-1];
        s[strlen(s)-i-1] = tmp;
    }

    int cnt = 10;
    while(cnt--){
        if(isH(s)){
            printf("%s is a palindromic number.", s);
            break;
        }
        int len = strlen(s);
        for(int i = len-1; i >= 0; --i)
            printf("%c", s[i]);
        printf(" + %s = ", s);

        int j = 0;
        for(int i = 0; i < len; ++i){
            int tmp = s[len-i-1] - '0' + s[i] - '0';
            p[i] = (tmp+j) % 10 + '0';
            j = (tmp + j) /10;
        }
        if(j != 0){ p[len] = j + '0'; p[len+1] = '\0';}
        else p[len] = '\0';
        for(int i = strlen(p)-1; i >= 0; --i)
            printf("%c", p[i]);
        printf("\n");
        strcpy(s, p);
    }
    if(cnt == -1) printf("Not found in 10 iterations.");
    return 0;
}
