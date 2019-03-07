#include <cstdio>
#include <vector>
using namespace std;

int main(){

//    freopen("data.in", "r", stdin);

    int N, M, K, isFirst = 1;
    scanf("%d %d", &N, &M);
    int v1, v2;
    vector<int> vec[1001];

    vector<int> indegree(1001, 0);

    for(int i = 0; i < M; ++i){
        scanf("%d %d", &v1, &v2);
        ++indegree[v2];
        vec[v1].push_back(v2);
    }

    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        int tmparr[N];
        int flag = 0;
        for(int j = 0; j < N; ++j)
            scanf("%d", &tmparr[j]);

        vector<int> degree = indegree;

        for(int j = 0; j < N; ++j){
            int tmp = tmparr[j];
            if(degree[tmp] == 0){
                for(int idx = 0; idx < vec[tmp].size(); ++idx)
                    --degree[vec[tmp][idx]];
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag){
            if(isFirst){
                printf("%d", i);
                isFirst = 0;
            }
            else printf(" %d", i);
        }
    }
    return 0;
}
