#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int a, ah, b, bh;
    int cnta = 0, cntb = 0;
    while(N--){
        scanf("%d %d %d %d", &a, &ah, &b, &bh);
        if(a + b == ah && a+b != bh)
            ++cnta;
        else if(a + b == bh && a+b != ah)
            ++cntb;
    }
    printf("%d %d", cntb, cnta);
    return 0;
}
