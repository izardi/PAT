#include <cstdio>
#include <cmath>

bool isPrime(int x){
    if( x <= 1)
        return false;
    for(int i = 2; i <= (int)sqrt(x); ++i)
        if( x % i == 0)
            return false;
    return true;
}

int main(){
    int N;
    scanf("%d", &N);
    int list[10005] = {0};
    int hash[10005] = {0};
    int tmp;

    for(int i = 1; i <= N; ++i){
        scanf("%d", &tmp);
        list[tmp] = i;
    }

    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        printf("%04d: ", tmp);
        if(list[tmp] == 0)
            printf("Are you kidding?\n");
        else if(hash[tmp] == 1)
            printf("Checked\n");
        else if(list[tmp] == 1)
            printf("Mystery Award\n");
        else if(isPrime(list[tmp]))
            printf("Minion\n");
        else printf("Chocolate\n");
        hash[tmp] = 1;
    }
    return 0;
}
