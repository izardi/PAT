#include <cstdio>
#include <vector>
using namespace std;

vector<int> T[100005];
double minPrice = 0;
int num = 0, minlevel = 10000005;

void dfs(int idx, int level){
    if(T[idx].empty()){
        if(minlevel > level){
            num = 1;
            minlevel = level;
        }
        else if(minlevel == level) ++num;
    }
    else{
        for(int i = 0; i < T[idx].size(); ++i)
            dfs(T[idx][i], level+1);
    }
}

int main(){
    int N, n, tmp;
    double P, r;
    scanf("%d %lf %lf", &N, &P, &r);
    for(int i = 0; i < N; ++i){
        scanf("%d", &n);
        for(int j = 0; j < n; ++j){
            scanf("%d", &tmp);
            T[i].push_back(tmp);
        }
    }
    dfs(0, 0);
    double res = P;
    for(int i = 0; i < minlevel; ++i)
        res = res*(1+r/100);
    printf("%.4lf %d", res, num);
    return 0;
}
