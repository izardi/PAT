#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, i;
    double P, r;
    scanf("%d %lf %lf", &N, &P, &r);
    vector< vector<int> > ve(N);
    int retailers[N] = {0};
    double price[N] = {P,};
    int num, tmp;
    for(i = 0; i < N; ++i){
        scanf("%d", &num);
        if(num < 1){
            scanf("%d", &tmp);
            retailers[i] = tmp;
        }
        else{
            for(int j = 0; j < num; ++j){
                scanf("%d", &tmp);
                ve[i].push_back(tmp);
            }
        }
    }
    double ans = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        for(vector<int>::iterator it = ve[tmp].begin(); it != ve[tmp].end(); ++it){
            que.push(*it);
            price[*it] = price[tmp]*(1+r/100);
        }
    }
    for(int i = 0; i < N; ++i){
        if(retailers[i] != 0)
            ans += retailers[i]*price[i];
    }
    printf("%.1lf\n", ans);
    return 0;
}