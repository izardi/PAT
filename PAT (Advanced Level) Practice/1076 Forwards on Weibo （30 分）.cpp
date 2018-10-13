#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, L;

int main(){
    scanf("%d%d", &N, &L);
    int tmp, follower;
    vector< vector<int> > G(1001);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &tmp);
        for(int j = 0; j < tmp; ++j){
            scanf("%d", &follower);
            G[follower].push_back(i);
        }
    }

    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        int vis[1001] = {0};
        scanf("%d", &tmp);
        queue<int> que;
        que.push(tmp);
        vis[tmp] = 1;
        int count = 0, level = 0, lend = tmp, nextlend = tmp;
        while(!que.empty()){
            int idx = que.front();
            que.pop();
            ++count;

            for(vector<int>::iterator it = G[idx].begin(); it != G[idx].end(); ++it){
                if(!vis[*it]){
                    que.push(*it);
                    nextlend = *it;
                    vis[*it] = 1;
                }
            }
            if(lend == idx){
                ++level;
                lend = nextlend;
            }
            if(level > L) break;
        }
        printf("%d\n", count-1);
    }
    return 0;
}
