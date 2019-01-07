#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    double P, r;
    scanf("%d %lf %lf", &N, &P, &r);
    r /= 100;
    
    int tmp;
    vector<int> V[100005];
    int root;

    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        if(tmp != -1)
            V[tmp].push_back(i);
        else
            root = i;
    }

    queue<int> que;
    que.push(root);

    int cur, level = 0, levelNum = 0, num = 0;
    int last = 0, levelLast = root;

    while(!que.empty()){
        cur = que.front();
        que.pop();
        ++levelNum;
        for(vector<int>::iterator it = V[cur].begin(); it != V[cur].end(); ++it){
            que.push(*it);
            last = *it;
        }

        if(cur == levelLast){
            ++level;
            levelLast = last;
            num = levelNum;
            levelNum = 0;
        }
    }

    double res = P;
    for(int i = 1; i < level; ++i)
        res *= (1+r);

    printf("%.2lf %d", res, num);
    return 0;
}