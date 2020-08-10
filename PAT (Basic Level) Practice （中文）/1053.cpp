#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, D;
    double e;
    scanf("%d %lf %d", &N, &e, &D);
    int k, cnt;
    double ei;
    int kz = 0, knkz = 0;

    for(int z = 0; z < N; ++z){
        scanf("%d", &k);
        cnt = 0;
        for(int i = 0; i < k; ++i){
            scanf("%lf", &ei);
            if(ei < e) ++cnt;
        }
        if(cnt > k/2){ 
            if(k > D) kz++;
            else knkz++;
        }
    }
    printf("%.1lf%% %.1lf%%", (double)100.0*knkz/N, (double)100.0*kz/N);
    return 0;
}
