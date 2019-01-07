#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int id, num, child;
    vector<int> Mb[100];

    for(int i = 0; i < M; ++i){
        scanf("%d %d", &id, &num);
        for(int j = 0; j < num; ++j){
            scanf("%d", &child);
            Mb[id].push_back(child);
        }
    }
    
    queue<int> que;
    que.push(1);

    int level = 1, curLevel=1, maxLevel=0, curP=0, maxP=0;
    int last = 1, levelLast = 1;

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        ++curP;
        for(vector<int>::iterator it = Mb[cur].begin(); it != Mb[cur].end(); ++it){
            que.push(*it);
            last = *it;
        }
        if(cur == levelLast){
            levelLast = last;
            if(maxP < curP){
                maxP = curP;
                level = curLevel;
            }
            curP = 0;
            ++curLevel;
        }
    }

    printf("%d %d", maxP, level);
    return 0;
}