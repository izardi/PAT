#include <cstdio>
#include <cmath>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int r, v;
    double res = 0, tmp = 0;;
    while(N--){
        scanf("%d %d", &r, &v);
        tmp = r*r + v*v;
        res = res > tmp ? res : tmp;
    }
    printf("%.2lf", sqrt(res));
    return 0;
}
