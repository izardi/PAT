#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXLEN 10001
vector<int> G[MAXLEN];
int vis[MAXLEN];
int dp[MAXLEN];
int N;
int maxdp;
int depth;
void DFS(int x, int level){
    vis[x] = 1;
    depth = depth > level ? depth : level;
    for(int i = 0; i < G[x].size(); i++)
        if(!vis[G[x][i]])
            DFS(G[x][i], level+1);
}
int main(){
    scanf("%d",&N);
    int x, y;
    int cnt = 0;
    for(int i = 1; i < N; i++){
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        vis[i] = 0;
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            depth = 0;
            DFS(i, 0);
            cnt++;
        }
        dp[1] = depth;
        maxdp = dp[1];
    }
    if(cnt > 1){
        printf("Error: %d components",cnt);
        return 0;
    }
    for(int i = 2; i <= N; i++){
        memset(vis, 0, sizeof(vis));
        depth = 0;
        DFS(i, 0);
        dp[i] = depth;
        maxdp = maxdp > depth ? maxdp : depth;
    }
    
    for(int i = 1; i <= N; i++)
        if(maxdp == dp[i])
            printf("%d\n", i);
    return 0;
}