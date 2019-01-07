#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main(){
    freopen("data.in", "r", stdin);
    int N, M, K, data, s1, s2, common;
    set<int> SET[50];
    
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &M);
        for(int j = 0; j < M; ++j){
            scanf("%d", &data);
            SET[i].insert(data);
        }
    }

    scanf("%d", &K);
    while(K--){
        common = 0;
        scanf("%d %d", &s1, &s2);
        --s1; --s2;
        for(set<int>::iterator it = SET[s1].begin(); it != SET[s1].end(); ++it)
            if(SET[s2].find(*it) != SET[s2].end())
                ++common;
        printf("%.1lf%%\n", double(common*100)/(SET[s1].size() + SET[s2].size() - common));
    }
    return 0;
}