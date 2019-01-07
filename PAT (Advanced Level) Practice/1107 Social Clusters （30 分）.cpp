#include <cstdio>
#include <algorithm>
using namespace std;
int father[1005] = {0};

int findFather(int x){
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}

bool cmp(const int a, const int b){
    return a > b;
}

int main(){
    // freopen("data.in", "r", stdin);
    int N, i, k, idx, cnt = 0;
    int isRoot[1005] = {0};
    int hash[1005] = {0};
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
        father[i] = i;
    for(i = 1; i <= N; ++i){
        scanf("%d:", &k);
        for(int j = 0; j < k; ++j){
            scanf("%d", &idx);
            if( !hash[idx] )
                hash[idx] = i;
            Union(i, findFather(hash[idx]));
        }
    }

    for(i = 1; i <= N; ++i)
        isRoot[findFather(i)]++;
    for(i = 1; i <= N; ++i)
        if(isRoot[i]) ++cnt;

    printf("%d\n", cnt);
    sort(isRoot, isRoot+N+1, cmp);

    for(i = 0; i < cnt; ++i){
        printf("%d", isRoot[i]);
        if(i != cnt-1)
            printf(" ");
    }
    return 0;
}
