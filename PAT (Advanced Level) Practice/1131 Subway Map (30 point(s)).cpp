#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int inf = 1000000000;

int N, M, K; // N <= 100 总的地铁线路数  M <= 100 站点数
int v1, v2;
int minCnt, minTransfer;
int vis[100000] = {0};
vector<int> path, fin_path;
vector<int> G[10000]; //station 的图
unordered_map<int, int> line;//记录station的lines用连个station经hash计算的到专属的line
                                //每个station可以对应多个line ///ATTENTION
int findMinTransfer(vector<int> a){
    int cnt = -1, preLine = 0;
    for(int i = 1; i < a.size(); ++i){
        if(line[a[i-1]*10000+a[i]] != preLine) ++cnt;
        preLine = line[a[i-1]*10000+a[i]];
    }   
    return cnt;
}

void DFS(int node, int cnt){
    if(node == v2 && (cnt < minCnt || (cnt == minCnt && findMinTransfer(path) < minTransfer))){
        minCnt = cnt;
        minTransfer = findMinTransfer(path);
        fin_path = path;
    }
    if(node == v2) return;
    for(int i = 0; i < G[node].size(); ++i){
        if(!vis[G[node][i]]){
            vis[G[node][i]] = 1;
            path.push_back(G[node][i]);
            DFS(G[node][i], cnt+1);
            path.pop_back();
            vis[G[node][i]] = 0;
        }
    }
}

int main(){
    //freopen("d.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d %d", &M, &v1);    
        for(int j = 1; j < M; ++j){
            scanf("%d", &v2);
            G[v1].push_back(v2);
            G[v2].push_back(v1);//无向图
            line[v1*10000+v2] = line[v2*10000+v1] = i;
            v1 = v2;
        }
    }// graph建立完毕
    scanf("%d", &K);

    while(K--){
        scanf("%d %d", &v1, &v2);
        minCnt = inf;
        minTransfer = inf;
        path.clear();
        path.push_back(v1);
        vis[v1] = 1;
        DFS(v1, 0);
        vis[v1] = 0;
        //Dijkstraf 只能用于有权图这个图显然是无权图不能用，只能用递归
        printf("%d\n", minCnt);
        int preLine = 0;
        int preTransfer = v1;
        for(int j = 1; j < fin_path.size(); ++j){// 在地j站不与前面同站是才打印pTf用来保存上一个的第一站
            if(line[fin_path[j-1]*10000+fin_path[j]] != preLine){
                if(preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, fin_path[j-1]);
                preLine = line[fin_path[j-1]*10000+fin_path[j]];
                preTransfer = fin_path[j-1];    
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, v2);
    }
    return 0;
}