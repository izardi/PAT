#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    else{
        for(int i = 2; i <= sqrt(n); ++i)
            if(n%i == 0) return false;
        return true;
    }
}

int main(int argc, char *argv[])
{
    int rank[10000] = {0};
    freopen("in", "r", stdin);
    int N, K, tmp;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &tmp);
        rank[tmp] = i;
    }
    scanf("%d", &K);
    while(K--){
        scanf("%d", &tmp);
        printf("%04d: ", tmp);
        if(rank[tmp] == -1)
            printf("Checked\n");
        else if(rank[tmp] == 0)
            printf("Are you kidding?\n");
        else{
            if(rank[tmp] == 1)
                printf("Mystery Award\n");
            else if(isPrime(rank[tmp]))
                printf("Minion\n");
            else printf("Chocolate\n");
            rank[tmp] = -1;
        }

    }
    
    return 0;
}
