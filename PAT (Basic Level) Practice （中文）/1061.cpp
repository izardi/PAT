#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int score[101] = {0};
    int right[101] = {0};
    for(int i = 0; i < M; ++i)
        scanf("%d", &score[i]);
    for(int i = 0; i < M; ++i)
        scanf("%d", &right[i]);
    int tmp;
    while(N--){
        int res = 0;
        for(int i = 0; i < M; ++i){
            scanf("%d", &tmp);
            if(right[i] == tmp)
                res += score[i];
        }
        printf("%d\n", res);
    }
    return 0;
}
