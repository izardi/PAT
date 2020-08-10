#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, K;
    scanf("%d", &N);
    int hash[101] = {0};
    int tmp;
    while(N--){
        scanf("%d", &tmp);
        ++hash[tmp];
    }
    scanf("%d", &K);
    int flag = 0;
    while(K--){
        scanf("%d", &tmp);
        if(flag) printf(" ");
        printf("%d", hash[tmp]);
        flag = 1;
    }
    return 0;
}
