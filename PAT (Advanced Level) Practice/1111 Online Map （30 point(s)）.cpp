#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int inf = 10000000;
int N, M;
int L[501][501];
int T[501][501];
int Dist[501];
int Time[501];
int vis[501];
int intersections[501] = {0};

vector<int> minLpath(501, -1);
vector<int> minTpath(501, -1);
vector<int> path;

void dfsL(int idx){
    if(idx != -1){
        path.push_back(idx);
        dfsL(minLpath[idx]);
    }
}

void dfsT(int idx){
    if(idx != -1){
        path.push_back(idx);
        dfsT(minTpath[idx]);
    }
}

int main(){
    fill(L[0], L[0] + 501 * 501, inf);
    fill(T[0], T[0] + 501 * 501, inf);
    fill(Dist, Dist + 501, inf);
    fill(Time, Time + 501, inf);
    scanf("%d %d", &N, &M);
    int v1, v2, one_way, length, time;

    for(int i = 0; i < M; ++i){
        scanf("%d %d %d %d %d", &v1, &v2, &one_way, &length, &time);
        L[v1][v2] = length;
        T[v1][v2] = time;
        if(!one_way){
            L[v2][v1] = length;
            T[v2][v1] = time;
        }
    }
    scanf("%d %d", &v1, &v2);
    
    Dist[v1] = 0;
    fill(vis, vis + 501, 0);
    for(int i = 0; i < N; ++i){
        int u = -1, min = inf;
        for(int j = 0; j < N; ++j)
            if(!vis[j] && min > Dist[j]){
                min = Dist[j];
                u = j;
            }
        if(u == -1) break;
        vis[u] = 1;
        for(int j = 0; j < N; ++j){
            if(!vis[j] && L[u][j] != inf){
                if(Dist[u] + L[u][j] < Dist[j]){
                    Dist[j] = Dist[u] + L[u][j];
                    minLpath[j] = u;
                    Time[j] = Time[u] + T[u][j];
                }else if(Dist[u] + L[u][j] == Dist[j] && Time[j] > Time[u] + T[u][j]){
                    Time[j] = Time[u] + T[u][j];
                    minLpath[j] = u;
                }
            }
        }
    }
    
    fill(vis, vis+501, 0);
    fill(Time, Time+501, inf);
    Time[v1] = 0;
    for(int i = 0; i < N; ++i){
        int u = -1, min = inf;
        for(int j = 0; j < N; ++j){
            if(!vis[j] && min > Time[j]){
                min = Time[j];
                u = j;
            }
        }
        if(u == -1) break;
        vis[u] = 1;
        for(int j = 0; j < N; ++j){
            if(!vis[j] && T[u][j] != inf){
                if(Time[u] + T[u][j] < Time[j]){
                    Time[j] = Time[u] + T[u][j];
                    minTpath[j] = u;
                    intersections[j] = intersections[u] + 1;
                }else if(Time[u] + T[u][j] == Time[j] && intersections[j] > intersections[u] + 1){
                    minTpath[j] = u;
                    intersections[j] = intersections[u] + 1;
                }
            }
        }
    }
    
    printf("Distance = %d", Dist[v2]);

    if(minLpath == minTpath){
        printf("; Time = %d: ", Time[v2]);
    }
    else{
        printf(": ");
        dfsL(v2);
        for(int i = path.size()-1; i >= 0; --i){
            if(i == path.size()-1)
                printf("%d", path[i]);
            else printf(" -> %d", path[i]);
        }
        printf("\n");
        printf("Time = %d: ", Time[v2]);
    }

    path.clear();
    dfsT(v2);
    for(int i = path.size()-1; i >= 0; --i){
        if(i == path.size()-1)
            printf("%d", path[i]);
        else printf(" -> %d", path[i]);
    }
    return 0;
}
