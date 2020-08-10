#include <cstdio>
#include <cmath>
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int id, x, y;
    double ma = 0, mi = 20000;
    int l, w, tmp, d;
    while(N--){
        scanf("%d %d %d", &tmp, &x, &y);
        d = abs(x)*abs(x) + abs(y)*abs(y);
        if(d < mi){
            mi = d;
            w = tmp;
        }
        if(d > ma){
            ma = d;
            l = tmp;
        }
    }
    printf("%04d %04d", w, l);
    return 0;
}
