#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    // freopen("data.in", "r", stdin);
    int N, Q, p1, p2;
    int hash[100005] = {0}, two[50005] = {0};

    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d %d", &p1, &p2);
        hash[p1] = hash[p2] = i;
    }
    int single[10005];
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i){
        scanf("%d", &single[i]);
        if(hash[single[i]])
            ++two[hash[single[i]]];
    }

    sort(single, single+Q);
    int flag = 1;
    int res = 0;
    for(int i = 0; i < Q; ++i){
        if(hash[single[i]] == 0 || two[hash[single[i]]] != 2)
            ++res;
    }
    printf("%d\n", res);
    for(int i = 0; i < Q; ++i){
        if(hash[single[i]] == 0 || two[hash[single[i]]] != 2){
            if(flag){
                printf("%05d", single[i]);
                flag = 0;
            }
            else printf(" %05d", single[i]);
        }
    }
    return 0;
}