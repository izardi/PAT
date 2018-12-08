#include <cstdio>
#include <cstring>

int main(){
    char s[100005];
    scanf("%s", s);

    int np[100005] = {0};
    int nt[100005] = {0};
    int len = strlen(s);
    int count = 0;
    int n = 0;

    for(int i = 0; i < len; ++i){
        if(s[i] == 'A')
            np[n++] = count;
        else if(s[i] == 'P')
            ++count;
    }

    int len1 = n;
    count = 0;

    for(int i = len-1; i >= 0; --i){
        if(s[i] == 'A')
            nt[--n] = count;
        else if(s[i] == 'T')
            ++count;
    }

    int res = 0;
    for(int i = 0; i < len1; ++i){
        res += np[i]*nt[i];
        res %= 1000000007;
    }
    printf("%d",res);

    return 0;
}