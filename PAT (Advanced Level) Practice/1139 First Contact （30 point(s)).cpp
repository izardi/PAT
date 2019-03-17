#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct Node{
    int f1, f2;
} node;

bool cmp(struct Node & a, struct Node & b){
    if(a.f1 != b.f1)
        return a.f1 < b.f1;
    return a.f2 < b.f2;
}

int main(){
//    freopen("data.in", "r", stdin);
    int N, M, K, v1, v2;
    string sv1, sv2;
    vector<int> G[10005];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        cin >> sv1 >> sv2;
        v1 = stoi(sv1); v2 = stoi(sv2);
        if(v1 < 0) v1 *= -1;
        if(v2 < 0) v2 *= -1;
        if(sv1.length() == sv2.length()){
            G[v1].push_back(v2);
            G[v2].push_back(v1); 
        }
        arr[v1 * 10000 + v2] = arr[v2 * 10000 + v1] = true;
    }

    scanf("%d", &K);
    int vis[10005] = {0};
    
    while(K--){
        scanf("%d %d", &v1, &v2); 
        if(v1 < 0) v1 *= -1;
        if(v2 < 0) v2 *= -1;
        vector<Node> ans;
        vis[v1] = vis[v2] = 1;
        for(int i = 0; i < G[v1].size(); ++i){
            if(!vis[G[v1][i]]){
                vis[G[v1][i]] = 1;
                for(int j = 0; j < G[v2].size(); ++j){
                    if(!vis[G[v2][j]] && true == arr[G[v1][i] * 10000 + G[v2][j]])
                        ans.push_back({G[v1][i], G[v2][j]});
                }
                vis[G[v1][i]] = 0;
            }
        }
        vis[v1] = vis[v2] = 0;
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int i = 0; i < ans.size(); ++i)
            printf("%04d %04d\n", ans[i].f1, ans[i].f2);
    }
    return 0;
}
