#include <cstdio>
#include <cmath>

int main(int argc, char *argv[])
{
//    freopen("in", "r", stdin);
    int N;
    char c;
    scanf("%d %c", &N, &c);
    int cnt = 0;
    int row = (int)sqrt((N+1)/2);   

    for(int i = 1; i < row; ++i){
        for(int k = 1; k < i; ++k)
            printf(" ");
        for(int k = 0; k < (row-i)*2+1; ++k)
            printf("%c", c);
        printf("\n");
    }

    for(int i = 0; i < row; ++i){
        for(int k = 1; k < row-i; ++k)
            printf(" ");
        for(int k = 0; k < i*2+1; ++k){
            printf("%c", c);
        }
        printf("\n");
    }
    printf("%d\n", N-row*row*2+1);
    return 0;
}
