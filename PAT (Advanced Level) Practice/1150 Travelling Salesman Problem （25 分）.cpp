#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int G[205][205];

int main(){
    int minidx, mindist = 1000000;
    int N, M, K;
    // freopen("data.in", "r", stdin);
    fill(G[0], G[0] + 205*205, 0);
    scanf("%d %d", &N, &M);
    int v1, v2, dist;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &v1, &v2, &dist);
        G[v1][v2] = G[v2][v1] = dist;
    }
    scanf("%d", &K);
    int n, tmparr[205];
    for(int i = 1; i <= K; ++i){
        printf("Path %d: ", i);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &tmparr[i]);
        
        dist = 0;
        int flag = 1;
        int hash[205] = {0};
        int j, pre = tmparr[0];
        hash[pre]++;
        for( j = 1; j < n; ++j){
            if(G[pre][tmparr[j]] == 0){
                break;
            }
            else{
                dist += G[pre][tmparr[j]];
                pre = tmparr[j];
                hash[pre]++;
            }
        }
        if(j != n){
            printf("NA (Not a TS cycle)\n");
            continue;
        }
        int cnt = 0;
        for( j = 1; j <= N; ++j){
            if(hash[j] == 2)
                ++cnt;
            else if(!hash[j]){
                flag = 0;
                break;
            }
        }
        printf("%d ", dist);
        if(cnt == 0 || flag == 0|| tmparr[0] != tmparr[n-1]) printf("(Not a TS cycle)\n");
        else{
            if(mindist > dist){
                mindist = dist;
                minidx = i;
            }
            if(cnt == 1 && hash[tmparr[0]] == 2) printf("(TS simple cycle)\n");
            else printf("(TS cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d", minidx, mindist);
    return 0;
}
