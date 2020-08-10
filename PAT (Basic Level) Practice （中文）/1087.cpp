#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int cnt = 0;
    int res = 0;
    int pre = -1;
    for(int i = 1; i <= N; ++i){
        res = i/2 + i/3 + i/5;
        if(res != pre){
            ++cnt;
            pre = res;
        }
    }
    printf("%d", cnt);
    return 0;
}
