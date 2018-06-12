#include <cstdio>
#include <cstring>

int N, M, K;
int G[1001][1001];
int vis[1001] = {0};
int cnt;

void DFS(int x){
    vis[x] = 1;
    for(int i = 1; i <= N; i++)
        if(G[x][i] == 1 && !vis[i])
            DFS(i);
}

int main(){
    memset(G, 0, sizeof(G));
    scanf("%d %d %d", &N, &M, &K);
    int x, y;
    while(M--){
        scanf("%d %d", &x, &y);
        G[x][y] = G[y][x] = 1;
    }
    while(K--){
        scanf("%d", &x);
        cnt = 0;
        vis[x] = 1;
        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                DFS(i);
                cnt++;
            }
        }
        for(int i = 1; i <= N; i++)
            vis[i] = 0;
        printf("%d\n", cnt - 1);
    }
    return 0;
}
