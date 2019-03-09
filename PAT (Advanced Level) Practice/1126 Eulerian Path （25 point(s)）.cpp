#include <cstdio>
#include <vector>
using namespace std;
int vis[505] = {0};
vector<int> G[505];
int cg = 0;
void dfs(int idx){
    vis[idx] = 1;
    ++cg;
    for(int i = 0; i < G[idx].size(); ++i)
        if(!vis[G[idx][i]])
            dfs(G[idx][i]);
}
int main(){
    // freopen("data.in", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);

    int v1, v2, cnt = 0;
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    for(int i = 1; i <= N; ++i){
        if(i != 1) printf(" ");
        printf("%d", G[i].size());
        if(G[i].size() % 2 == 0)
            cnt++;
    }
    printf("\n");
    dfs(1);
    if(cnt == N && cg == N)
        printf("Eulerian\n");
    else if(cnt == N - 2 && cg == N)
        printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}
