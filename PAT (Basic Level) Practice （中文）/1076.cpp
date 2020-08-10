#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d\n", &N);
    char a, b;
    while(N--){
        for(int i= 0; i < 4; ++i){
            scanf("%c-%c", &a, &b);
            getchar();
            if(b == 'T')
                printf("%d", a-'A'+1);
        }
    }
    return 0;
}
