#include <cstdio>
const int INF = 123456789;
#include <cstring>
const int MAX = 501;
int N, M, C1, C2;
int nums[MAX], vis[MAX], G[MAX][MAX];
int cnt = 0, maxnum = 0;
int mind = INF;

void dfs(int curr, int dest, int dist, int num){
    if(curr == dest){
        if(dist < mind){
            cnt = 1;
            mind = dist;
            maxnum = num;
        }else if(dist == mind){
            cnt++;
            if(maxnum < num)
                maxnum = num;
        }
        return;
    }
    
    if(dist > mind) return;
    for(int i = 0; i < N; i++){
        if(!vis[i] && G[curr][i] != INF){
            vis[i] = 1;
            dfs(i,dest, dist+G[curr][i], num+nums[i]);
            vis[i] = 0;
        }
    }
}
int main(){

    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for(int i = 0; i < N; i++)
        scanf("%d", &nums[i]);
    for(int i = 0; i < N; i++){
        vis[i] = 0;
        for(int j = 0; j < N; j++)
            G[i][j] = INF;
    }
    
    int x, y, z;
    while(M--){
        scanf("%d %d %d", &x, &y, &z);
        G[x][y] = G[y][x] = z;
    }
    dfs(C1, C2, 0, nums[C1]);
    
    printf("%d %d\n", cnt, maxnum);
}