#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    unordered_map<int, vector<int> > mp;

    while(N--){
        scanf("%d %d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    while(M--){
        scanf("%d", &a);
        unordered_map<int, int> mpp;
        vector<int> arr;
        for(int i = 0; i < a; ++i){
            scanf("%d", &b);
            arr.push_back(b);
            mpp[b] = 1;
        }
        int flag = 0;
        for(int i = 0; i < a; ++i){
            for(auto it = mp[arr[i]].begin();
                    it != mp[arr[i]].end(); ++it){
                if(mpp[*it]){
                    printf("No\n");
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("Yes\n");
    }
    return 0;
}
