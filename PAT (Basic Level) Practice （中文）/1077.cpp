#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    double g1;
    for(int i = 0; i < N; ++i){
        scanf("%lf", &g1);
        double g2 = 0, tmp;
        int cnt = 0; 
        double mi = 50, ma = 0;
        for(int i = 0; i < N-1; ++i){
            scanf("%lf", &tmp);
            if(tmp >= 0 && tmp <= M){
                if(mi > tmp) mi = tmp;
                if(ma < tmp) ma = tmp;
                g2 += tmp;
                ++cnt;
            }
        }
        g2 -= ma; g2 -= mi; cnt -=2;
        g2 /= cnt;
        printf("%d\n", int((g1+g2)/2+0.5));
    }
    return 0;
}
