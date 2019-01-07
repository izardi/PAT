#include <cstdio>
#include <vector>   
using namespace std;

const int INF = 10000000;
int capacity, num_s, idx_p, roads;
int curr_num[510] = {0};
int G[510][510];
int dist[510];
bool vis[510] = {false};
vector<int> road[510];
vector<int> path, temppath;
int mintake = INF, minsend = INF;

void Dijkstra(){
    dist[0] = 0;
    for(int i = 0; i <= num_s; i++){
        int u = -1, minn = INF;
        if(!vis[i] && minn > dist[i]){
            u = i;
            minn = dist[i];
        }
        if (u == -1) return;
        vis[u] = true;
        
        for(int v = 0; v <= num_s; v++)
            if(!vis[v] && G[u][v] != INF){
                if(G[u][v] + dist[u] < dist[v]){
                    dist[v] = G[u][v] + dist[u];
                    road[v].clear();
                    road[v].push_back(u);
                }
                else if(G[u][v] + dist[u] == dist[v])
                    road[v].push_back(u);
            }
    }
}
void DFS(int v){
    if(v == 0){
        int send = 0; int take = 0;
        for(int i = temppath.size() - 1; i >= 0; i--)
            send += (capacity - curr_num[temppath[i]]);
        if(send < 0){
            send = 0;
            take = -1*send;
        }
        else
            take = 0;
        if(send < minsend){
            minsend = send;
            mintake = take;
            path = temppath;
        }
        else if( send == minsend)
            if(take < mintake){
                mintake = take;
                path = temppath;
            }
        return;
    }
    temppath.push_back(v);
    for(int i = 0; i < road[v].size(); i++)
        DFS(road[v][i]);
    temppath.pop_back();
}
int main(){
    scanf("%d %d %d %d", &capacity, &num_s, &idx_p, &roads);
    capacity /= 2;
    for(int i = 1; i <= num_s; i++){
        scanf("%d", &curr_num[i]);
        dist[i] = INF;
        for(int j = 0; j <= num_s; j++)
            G[i][j] = INF;
    }
    for(int i = 0; i <= num_s; i++)
        G[0][i] = INF;
    int x, y;
    
    for(int i = 0; i < roads; i++){
        scanf("%d %d", &x, &y);
        scanf("%d", &G[x][y]);
        G[y][x] = G[x][y];
    }
    
    Dijkstra();
    DFS(idx_p);
    printf("%d ", minsend);
    printf("0");
    for(int i = path.size() - 1; i >= 0; i--)
        printf("->%d",path[i]);
    printf(" %d", mintake);
    return 0;
}