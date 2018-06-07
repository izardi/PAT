#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100;
int N, M, G[MAX][MAX];
int inDegree[MAX], outDegree[MAX];
int vis[MAX];

int main(){
    scanf("%d %d", &N, &M);
    int x, y, z;
    
    for(int i = 1; i <= N; i++){
        inDegree[i] = outDegree[i] = vis[i] = 0;
        for(int j = 1; j <= N; j++)
            G[i][j] = 0;
    }
    
    while(M--){
        scanf("%d %d", &x, &z);
        outDegree[x]++;
        for(int i = 0; i < z; i++){
            scanf("%d", &y);
            G[x][y] = 1;
            inDegree[y]++;
        }
    }
    queue<int> Q;
    int rear;
    for(int i = 1; i <= N; i++)
        if(!inDegree[i]){
            Q.push(i);
            rear = i;
        }
        
    int v, cnt = 0;
    int prerear = rear;
    int flag = 1;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for(int i = 1; i <= N; i++){
            if(G[v][i]){
                Q.push(i);
                rear = i;
            }
            if(!outDegree[v] && !vis[v]){
                cnt++;
                vis[v] = 1;
            }
        }
        if(v == prerear){
            prerear = rear;
            if(flag){
                printf("%d", cnt);
                flag = 0;
            }
            else
                printf(" %d", cnt);
            cnt = 0;
        }
    }
}