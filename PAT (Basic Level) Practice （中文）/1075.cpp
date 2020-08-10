#include <cstdio>

struct Node{
    int Add, data, nex;
} L[100000];

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int F, N, K;
    scanf("%d %d %d", &F, &N, &K);
    int ad;
    for(int i = 0; i < N; ++i){
        scanf("%d", &ad);
        scanf("%d %d", &L[ad].data, &L[ad].nex);
        L[ad].Add = ad;
    }
    while(F != -1){
        printf("%d %d %d\n", L[F].Add, L[F].data, L[F].nex);
        F = L[F].nex;
    }
    return 0;
}
