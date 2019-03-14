#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, K;
int G[205][205];

int main(){
    scanf("%d %d", &N, &M);
    int v1, v2;
    fill(G[0], G[0] + 205*205, 0);
    
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1; 
    }
    scanf("%d", &K);
    int n, tmparr[205];
    while(K--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &tmparr[i]);
        int pre = tmparr[0];
        int hash[205] = {0};
        hash[pre]++;
        int flag = 1;
        for(int i = 1; i < n; ++i){
            if(G[pre][tmparr[i]] == 0){
                flag = 0;
                break;
            }else{
                pre = tmparr[i];
                hash[pre]++;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            if(hash[i] == 2)
                cnt++;
            else if(hash[i] == 0){
                flag = 0;
                break;
            }
        }
        if(flag && tmparr[0] == tmparr[n-1] && hash[tmparr[0]] == 2 && cnt == 1) flag = 1;
        else flag = 0;
        if(flag) printf("YES\n");
        else printf("NO\n"); 
    }
    return 0;
}
