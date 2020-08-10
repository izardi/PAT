#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, i;
    scanf("%d", &N);
    double tmp, res = 0.0;
    long long sum = 0;
    for(i = 0; i < N; ++i){
        scanf("%lf", &tmp);
        sum +=(long long)(tmp*1000)*(i+1)*(N-i);
    }
    printf("%.2lf", (sum/1000.0));
    return 0;
}
