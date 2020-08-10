#include <cstdio>
#include <cstring>
#include <cctype>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char bad[128] = {0};
    char c;
    while((c = getchar()) != '\n'){
        if(c >= 'A' && c <= 'Z')
            bad[c - 'A' + 'a'] = 1;
        bad[c] = 1;
    }
    if(bad['+']){
        for(int i = 'A'; i <= 'Z'; ++i)
            bad[i] = 1;
    }
    int flag = 1;
    while((c = getchar()) != '\n')
        if(!bad[c]){
            printf("%c", c);
            flag = 0;
        }
    if(flag) printf("\n");
    return 0;
}
