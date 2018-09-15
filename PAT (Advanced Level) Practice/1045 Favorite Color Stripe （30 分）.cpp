#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int tmp, N, M, L, i, res = 0;
    int favorite[201] = {0}, dp[201] = {0};

    scanf("%d%d", &N, &M);

    for(i = 1; i <= M; i++){
        scanf("%d", &tmp);
        favorite[tmp] = i;
    }

    scanf("%d", &L);
    for(i = 1; i <= L; i++){
        scanf("%d", &tmp);
        if(tmp <= N && favorite[tmp]){
            res = max(dp[favorite[tmp]], dp[favorite[tmp]-1]) + 1;
            dp[favorite[tmp]] = res;
        }
    }

    printf("%d", res);
    return 0;
}
