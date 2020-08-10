#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int M, K;
    scanf("%d", &M);
    int num;
    while(M--){
        scanf("%d", &K);
        int flag = 0;
        int cnt = 10;
        num = K*K;
        while(cnt < K) cnt *= 10;
        int i;
        for(i = 1; i < 10; ++i){
            if(num*i % cnt == K){
                flag = 1;
                break;
            }
        }
        if(flag) printf("%d %d\n", i, num*i);
        else printf("No\n");
    }
    return 0;
}
