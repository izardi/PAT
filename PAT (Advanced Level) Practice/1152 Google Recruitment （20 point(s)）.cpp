#include <cstdio>
#include <cstdlib>

bool isPrime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i*i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

int main(){
    int L, K;
    scanf("%d %d\n", &L, &K);
    char s[10005], s1[11];
    scanf("%s", s);
    for(int i = 0; i <= L - K; ++i){
        for(int j = 0; j < K; ++j)
            s1[j] = s[i+j];
        if(isPrime(atoi(s1))){
            printf("%s", s1);
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
