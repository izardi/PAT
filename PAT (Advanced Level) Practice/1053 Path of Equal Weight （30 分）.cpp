#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    int w;
    vector<int> child;
};
int S;
vector<Node> vec(100);
vector<int> path(100);
void dfs(int idx, int nodeNum, int sum){
    if(sum > S) return;
    if(sum == S){
        if(vec[idx].child.size() != 0) return;
        printf("%d", vec[0].w);
        for(int i = 1; i < nodeNum; i++)
            printf(" %d", vec[path[i]].w);
        printf("\n");
        return;
    }
    for(int i = 0; i < vec[idx].child.size(); ++i){
        path[nodeNum] = vec[idx].child[i];
        dfs(vec[idx].child[i], nodeNum+1, sum + vec[vec[idx].child[i]].w);
    }
}
bool cmp(const int a, const int b){
    return vec[a].w > vec[b].w;
}
int main(){
    int i, N, M;
    scanf("%d %d %d", &N, &M, &S);
    for(i = 0; i < N; i++ ){
        scanf("%d", &vec[i].w);
    }
    int root, n, tmp;
    for(i = 0; i < M; i++){
        scanf("%d %d", &root, &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &tmp);
            vec[root].child.push_back(tmp);
        }
        sort(vec[root].child.begin(), vec[root].child.end(), cmp);
    }
    dfs(0, 1, vec[0].w);
    return 0;
}
