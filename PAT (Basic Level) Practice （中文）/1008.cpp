#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    int N, M;
    scanf("%d %d\n", &N, &M);
    int arr[N];
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    M %= N;
    int flag = 0;

    for(int i = N - M; i < N; ++i){
        if(flag) printf(" ");
        printf("%d", arr[i]);
        flag = 1;
    }
    for(int i = 0; i < N-M; ++i){
        if(flag) printf(" ");
        printf("%d", arr[i]);
        flag = 1;
    }
    return 0;
}
