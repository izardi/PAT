#include <cstdio>
#include <vector>
using namespace std;

int main(){
    // freopen("data.in", "r", stdin);
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<int> G[10005];
    int v1, v2;
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(i);
        G[v2].push_back(i);
    }
    scanf("%d", &K);
    int n;
    while(K--){
        int flag = 1;
        int hash[10005] = {0};
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &v1);
            for(int j = 0; j < G[v1].size(); ++j)
                hash[G[v1][j]] = 1;
        }
        for(int i = 0; i < M; ++i)
            if(!hash[i]){
                flag = 0;
                break;
            }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
