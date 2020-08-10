#include <cstdio>
#include <cstring>
int main(int argc, char *argv[])
{
    
    freopen("in", "r", stdin);
    char s[100005];
    scanf("%[^\n]", s);
    long long res = 0;
    int tmp;
    for(int i = 0; i < strlen(s); ++i){
        tmp = s[i] - 'A';
        if( tmp >= 0 && tmp < 26)
            res += (tmp +1);
        else{
            tmp = s[i] - 'a';
            if( tmp >= 0 && tmp < 26)
                res += (tmp +1);
        }
    }
    int cnt[2] = {0};
    while(res != 0){
        ++cnt[res%2];
        res /= 2;
    }
    printf("%d %d", cnt[0], cnt[1]);
    return 0;
}
