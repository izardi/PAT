#include <cstdio>
#include <algorithm>
using namespace std;
int cmp(const int &a, const int &b) { return a > b;}

int main(){
    int N, M, f[10001];
    scanf("%d%d", &N, &M);
    for(int i = 1; i <=N; ++i)
        scanf("%d", &f[i]);
    sort(f+1, f+N+1, cmp);
    int dp[M+1] = {0};
    int choice[N+1][M+1];

    for(int i = 1; i <= N; ++i){
        for(int v = M; v >= f[i]; --v){
            if(dp[v] <= dp[v-f[i]] + f[i]){
                dp[v] = dp[v-f[i]] + f[i];
                choice[i][v] = 1;
            }
            else
                choice[i][v] = 0;
        }
    } 
    if(dp[M] != M) printf("No Solution");
    else{
        int flag[N+1] = {0};
        int k = N, num = 0, v = M;
        while(k >= 0){
            if(choice[k][v] == 1){
                flag[k] = 1;
                v -= f[k];
                num++;
            }
            k--;
        }
        for(int i = N; i >= 1; --i){
            if(flag[i]){
                printf("%d", f[i]);
                --num;
                if(num > 0) printf(" ");
            }
        }
    }
    return 0;
}