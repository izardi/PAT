#include <cstdio>
#include <cmath>

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); ++i)
        if(n%i == 0) return false;
    return true;
}

int nextPrime(int n){
    while(!isPrime(n)) ++n;
    return n;
}

void quadraticProbing(int* htable, int hsize, int n){
    for(int i = 0; i < hsize; ++i){
        int idx = (n + i*i) % hsize;
        if(htable[idx] == 0){
            htable[idx] = n;
            printf("%d", idx);
            return;
        }
    }
    printf("-");
}

int main(){
    int M, N, i, tmp;
    scanf("%d %d", &M, &N);
    M = nextPrime(M);
    int htable[M] = {0};
    for(i = 0; i < N; ++i){
        scanf("%d", &tmp);
        quadraticProbing(htable, M, tmp);
        if(i != N-1) printf(" ");
    }    
    return 0;
}
