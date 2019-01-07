#include <cstdio>
const int MAXV = 510;
const int INF = 10000000;

int N, M, S, D;
struct node{
    int distance;
    int toll;
}G[MAXV][MAXV];

int dis[MAXV], cost[MAXV];
bool vis[MAXV] = {false};
int road[MAXV];

void Dijkstra(int s){
    for(int i = 0; i < N; i++) road[i] = i;
    dis[s] = 0;
    cost[s] = 0;
    for(int i = 0; i < N; i++){
        int u = -1, Min = INF;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dis[j] < Min){
                Min = dis[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < N; v++){
            if(!vis[v] && G[u][v].distance != INF){
                if(dis[u] + G[u][v].distance < dis[v]){
                    dis[v] = dis[u] + G[u][v].distance;
                    cost[v] = cost[u] + G[u][v].toll;
                    road[v] = u;
                }
                else if(dis[u] + G[u][v].distance == dis[v]){
                    if(cost[u] + G[u][v].toll < cost[v]){
                        cost[v] = cost[u] + G[u][v].toll;
                        road[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v){
    if(v == S){
        printf("%d ", v);
        return;
    }
    DFS(road[v]);
    printf("%d ", v);
}

int main(){
    scanf("%d %d %d %d",&N, &M, &S, &D);
    int u, v;
    
    for(int i = 0; i < N; i++){
        cost[i] = dis[i] = INF;
        for(int j = 0; j < N; j++)
            G[i][j].distance = G[i][j].toll = INF;
    }
    
    for(int i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        scanf("%d %d", &G[u][v].distance, &G[u][v].toll);
        G[v][u].distance = G[u][v].distance;
        G[v][u].toll = G[u][v].toll;
    }
    
    Dijkstra(S);
    DFS(D);
    printf("%d %d\n", dis[D], cost[D]);
    return 0;
}
