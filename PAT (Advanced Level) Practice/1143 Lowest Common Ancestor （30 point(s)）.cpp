#include <cstdio>
#include <map>
using namespace std;
int main(){
    int M, N;
    map<int, bool> mp;
    int data[10005] = {0};
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &data[i]);
        mp[data[i]] = true;
    }
    int u, v, a;
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &u, &v);

        for(int j = 0; j < N; ++j){
            a = data[j];
            if((a >= u && a <= v) || (a <= u && a >= v))
                break;
        }
        if(mp[u] == 0 && mp[v] == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if(a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}