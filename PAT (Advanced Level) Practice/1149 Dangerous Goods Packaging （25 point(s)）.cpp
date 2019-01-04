#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main(){
    int N, M, tmp, id1, id2;
    scanf("%d %d", &N, &M);
    map<int, vector<int> > mp;
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &id1, &id2);
        mp[id1].push_back(id2);
        mp[id2].push_back(id1);
    }

    while(M--){
        scanf("%d", &tmp);
        int hash[100005] = {0};
        int flag = 0;
        for(int i = 0; i < tmp; ++i){
            scanf("%d", &id1);
            if(!hash[id1]){
                hash[id1] = 1;
                for(vector<int>::iterator it = mp[id1].begin(); it != mp[id1].end(); ++it)
                    hash[*it] = 1;
            }
            else flag = 1;
        }
        if(flag)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}