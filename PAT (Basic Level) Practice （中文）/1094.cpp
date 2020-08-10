#include <cstdio>
#include <cstring>

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int L, K;
    char s[1005];
    scanf("%d %d", &L, &K);
    scanf("\n%s", s);    
    for(int i = 0; i <= L - K; ++i){
        int num = 0;
        for(int j = i; j < i + K; ++j)
            num = num*10 + s[j]-'0';
        if(isPrime(num)){
            for(int j = i; j < i + K; ++j)
                printf("%c", s[j]);
            return 0;
        }
    }
    printf("404");
    return 0;
}
