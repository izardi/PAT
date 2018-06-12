#include <cstdio>
#include <cmath>

bool isPrime(int n){
    if( n == 0 || n == 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(!(n % i))
            return false;
    return true;
}
int ReverseNumber(int N, int D){
    int sum = 0;
    do{
        sum = sum*D + N % D;
        N /= D;
    }while(N!=0);
    return sum;
}

int main(){
    int N, D;
    while(scanf("%d",&N), N >= 0){
        scanf("%d", &D);
        if(isPrime(N) && isPrime(ReverseNumber(N, D)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
