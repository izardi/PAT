#include <cstdio>
#include <cstring>
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int hash[128] = {0};
    char ch;
    while((ch = getchar()) != EOF){
        ++hash[ch];
    }
    char s[] = "PATest";
    while(1){
        int flag = 1;
        for(int i = 0; i < 6; ++i)
            if(hash[s[i]] != 0){
                --hash[s[i]];
                printf("%c", s[i]);
                flag = 0;
            }
        if(flag) break;
    }
    return 0;
}
