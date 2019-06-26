#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int x, y, z;
};
int M, N, L, T;
int vis[61][1287][129] = {0};
int G[61][1287][129];
int X[6] = {0, 0, 0, 0, 1, -1};//上下左右前后 
int Y[6] = {0, 0, -1, 1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

int judege(int x, int y, int z){
    if( x < 0 || x > M-1 || y < 0 || y > N-1 || z < 0 || z > L-1) return 0;
    if(G[z][x][y] == 0 || vis[z][x][y] == true) return 0;
    return 1;
}
int BFS(int z, int x, int y){
    int ans = 0;
    Node tem;
    tem.x = x; tem.y = y; tem.z = z;
    queue<Node> que;
    que.push(tem);
    vis[z][x][y] = 1;
    while(!que.empty()){
        Node t = que.front();
        que.pop();
        ++ans;
        for(int i = 0; i < 6; ++i){
            int tmpx = t.x + X[i];
            int tmpy = t.y + Y[i];
            int tmpz = t.z + Z[i];
            if(judege(tmpx, tmpy, tmpz)){
                vis[tmpz][tmpx][tmpy] = 1;
                tem.x = tmpx;
                tem.y = tmpy;
                tem.z = tmpz;
                que.push(tem);
            }
        }
    }
    if(ans < T) ans = 0;
    return ans;
}

int main(){
    //freopen("d.txt", "r", stdin);
    scanf("%d%d%d%d", &M, &N, &L, &T);
    int res = 0;
    for(int i = 0; i < L; ++i){
        for(int j = 0; j < M; ++j)
            for(int k = 0; k < N; ++k){
                scanf("%d", &G[i][j][k]);
            }
    }
    for(int i = 0; i < L; ++i)
        for(int j = 0; j < M; ++j)
            for(int k = 0; k < N; ++k){
                if(G[i][j][k] == 1 && vis[i][j][k] == false){
                    res += BFS(i, j, k);
                }
            }
    printf("%d", res);
}