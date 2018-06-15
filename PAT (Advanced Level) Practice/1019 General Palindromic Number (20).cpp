#include <cstdio>

int main(){
    int N, D;
    scanf("%d %d", &N, &D);
    int result[32] = {0};
    int cnt = 0;
    do{
        result[cnt++] = N % D;
        N /= D;
    }while( N != 0 );

    int i;
    for(i = 0; i < cnt/2; i++)
        if(result[i] != result[cnt-i-1])
            break;
    if(i != cnt/2)
        printf("No\n");
    else
        printf("Yes\n");
    for(i = cnt - 1; i >= 0; i--){
        if(i == 0)
            printf("%d\n", result[i]);
        else
            printf("%d ", result[i]);
    }
    return 0;
}