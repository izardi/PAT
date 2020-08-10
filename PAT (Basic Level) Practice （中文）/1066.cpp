#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int M, N, A, B, H, tmp;
    scanf("%d %d %d %d %d", &M, &N, &A, &B, &H);
    for(int i = 0; i < M; ++i){
        for(int j= 0; j < N; ++j){
            scanf("%d", &tmp);
            if(j != 0) printf(" ");
            if(tmp >= A && tmp <= B)
                printf("%03d", H);
            else printf("%03d", tmp);
        }
        printf("\n");
    }
    return 0;
}
