#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int N, K, P, maxFacSum = -1;
vector<int> v, ans, tmpAns;

void dfs(int idx, int tmpSum, int tmpK, int tmpFacSum){
    if(tmpK == K){
        if(tmpSum == N && tmpFacSum > maxFacSum){
            ans = tmpAns;
            maxFacSum = tmpFacSum;
        }
        return;
    }
    while(idx >= 1){
        if(tmpSum + v[idx] <= N){
            tmpAns[tmpK] = idx;
            dfs(idx, tmpSum + v[idx], tmpK+1, tmpFacSum+idx);
        }
        --idx;
    }
}
int main(){
    //freopen("d.txt", "r", stdin);
    scanf("%d %d %d", &N, &K, &P);
    int tmp = 0;
    int idx =1;
    while(tmp <= N){
        v.push_back(tmp);
        tmp = pow(idx, P);
        ++idx;
    }
    tmpAns.resize(K);
    dfs(v.size() - 1, 0, 0, 0);
    if(maxFacSum == -1){
        printf("Impossible\n");
    }
    else{
        printf("%d = ", N);
        for(int i = 0; i < ans.size(); ++i){
            if(i != 0) printf(" + ");
            printf("%d^%d", ans[i], P);
        }
    }
    return 0;
}