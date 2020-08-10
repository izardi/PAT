#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);  
    int N;
    char c;
    scanf("%d %c", &N, &c);
    int row = (N+1) / 2;
    for(int i = 0; i < N; ++i)
        printf("%c", c);
    printf("\n");
    for(int i = 0; i < row - 2; ++i){
        printf("%c", c);
        for(int j = 0; j < N-2; ++j)
            printf(" ");
        printf("%c\n", c);
    }
    for(int i = 0; i < N; ++i)
        printf("%c", c);
    return 0;
}
