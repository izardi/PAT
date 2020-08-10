#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);

    int N;
    scanf("%d", &N);
    long long res = 0;
    int tmp;
    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        res += (tmp*10 + tmp)*(N-1);
    }
    printf("%lld", res);
    return 0;
}
