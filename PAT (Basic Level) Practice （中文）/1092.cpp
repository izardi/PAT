#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[1003] = {0};
    int ma = 0;
    int tmp;
    while(M--){
        for(int i = 1; i <=N; ++i){
            scanf("%d", &tmp); 
            arr[i] += tmp;
            if(arr[i] > ma)
                ma = arr[i];
        }
    }
    printf("%d\n", ma);
    int flag = 0;
    for(int i = 1; i <= N; ++i)
        if(ma == arr[i]){
            if(flag) printf(" ");
            printf("%d", i);
            flag = 1;
        }
    return 0;
}
