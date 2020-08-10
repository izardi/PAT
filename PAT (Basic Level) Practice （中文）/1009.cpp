#include <cstdio>
#include <cstring>

int main(){
    freopen("in", "r", stdin);
    char s[81];
    scanf("%[^\n]", s);
    int len = strlen(s);
    int p = len;
    for(int i = len -1; i >= 0; --i){
        if(s[i] == ' '){
            for(int j = i+1; j < p; ++j)
                printf("%c", s[j]);
            printf(" ");
            p = i;
        }
    }
    for(int i = 0; i < p; ++i)
        printf("%c", s[i]);
    return 0;
}
