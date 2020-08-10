#include <cstdio>

int main(int argc, char *argv[]){
    freopen("in", "r", stdin);
    int M, N;
    scanf("%d %d", &M, &N);
    int prime[10002];
    int cnt = 0, i = 2;
    
    int flag;
    while(cnt <= N){
        flag = 0;
        for(int j = 2; j*j <= i; ++j){
            if(i % j == 0){
                flag = 1;
                break;
            }
            if(flag) break;
        }
        if(!flag) prime[++cnt] = i;
        ++i;
    }

    flag = 0;
    for( i = M; i <= N; ++i){
        if(flag) printf(" ");
        printf("%d", prime[i]);
        ++flag;
        if(flag == 10){
            flag = 0;
            printf("\n");
        }
    }
    return 0;
}
