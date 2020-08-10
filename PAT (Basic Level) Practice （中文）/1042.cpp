#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int hash[128] = {0};
    char s[1001];
    scanf("%[^\n]", s);
    int maxi= 'a';
    for(int i = 0; i < strlen(s); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = 'a' + s[i] - 'A';
        }
        if((s[i] >= 'a' && s[i] <= 'z')){
            ++hash[s[i]];
        }
    }
    for(int i = 'a'; i <= 'z'; ++i)
        if(hash[i] > hash[maxi])
            maxi = i;
    printf("%c %d", maxi, hash[maxi]);
    return 0;
}
