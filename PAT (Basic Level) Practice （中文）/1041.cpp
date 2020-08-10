#include <cstdio>

struct Node{
    long long id;
    int site;
}T[10001];

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int tmp;
    long long id;
    int site;
    for(int i = 0; i < N; ++i){
        scanf("%lld %d %d", &id, &tmp, &site);
        T[tmp].id = id;
        T[tmp].site = site;
    }
    scanf("%d", &tmp);
    while(tmp--){
        scanf("%d", &site);
        printf("%lld %d\n", T[site].id, T[site].site);
    }
    return 0;
}
