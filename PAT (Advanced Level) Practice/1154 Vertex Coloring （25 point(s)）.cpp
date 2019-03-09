#include <cstdio>
#include <map>
#include <vector>
using namespace std;


int main(){
//    freopen("data.in", "r", stdin);
    int N, M, K;
    scanf("%d %d", &N, &M);
    int v1, v2;
    vector<int> vec[10005];
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &v1, &v2);
        vec[v1].push_back(v2);
//        vec[v2].push_back(v1);
    }
    scanf("%d", &K);
    int tmp[10005] = {0};
    while(K--){
        map<int, int> mp;
        int flag = 1, cnt = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", &tmp[i]);
            if( !mp[tmp[i]] ){
                mp[tmp[i]] = 1;
                cnt++;
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < vec[i].size(); ++j){
                if(tmp[i] == tmp[vec[i][j]]){
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) printf("No\n");
        else printf("%d-coloring\n", cnt);
    }
    return 0;
}
