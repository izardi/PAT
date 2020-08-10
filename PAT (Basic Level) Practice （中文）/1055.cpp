#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    char name[9];
    int high;
} T[10005];

bool cmp(Node a, Node b){
    if(a.high != b.high)
        return a.high > b.high;
    else 
        return strcmp(a.name, b.name) < 0;
}
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("\n%s %d", T[i].name, &T[i].high);
    }
    sort(T, T + N, cmp);
    int row = K;
    int m;
    int cnt = 0;

    while(row){
        if(row == K)
            m = N-N/K*(K-1);
        else m = N/K;
        vector<char*> res(m);
        int j = m/2;
        res[j] = T[cnt].name;

        for(int i = cnt + 1; i < cnt + m; i += 2)
            res[--j] = T[i].name;
        j = m/2;
        for(int i = cnt+2; i < cnt + m ; i += 2)
            res[++j] = T[i].name;

        for(int i = 0; i < m; ++i){
            if(i) printf(" ");
            printf("%s", res[i]);
        }
        printf("\n");
        --row;
        cnt += m;
    }
    return 0;
}
