#include <cstdio>

int main(){
    long int N;
    scanf("%ld", &N);
    printf("%ld=", N);
    if(N == 1){
        printf("1");
        return 0;
    }
    int primes[100000] = {0};
    for(int i = 2; i < 100000; ++i)
        for(int j = 2; i*j < 100000; ++j)
            primes[i*j] = 1;
    bool isFirst = true;
    for(int i = 2; N >= 2; ++i){
        int cnt = 0;
        while(!primes[i] && (N%i == 0)){
            N /= i;
            cnt++;
        }
        if(cnt){
            if(!isFirst)
                printf("*");
            printf("%d", i);
            isFirst = false;
        }
        if(cnt > 1) printf("^%d", cnt);
    }
    return 0;
}
