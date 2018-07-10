#include <cstdio>

int main(){
    int i, N, cnt = 0, array[10001] = {0};
    scanf("%d", &N);
    int data[N];
    for(i = 0; i < N; i++){
        scanf("%d", &data[cnt]);
        array[data[cnt]]++;
        cnt++;
    }
    for(i = 0; i < N; i++)
        if(array[data[i]] == 1)
            break;
    if(i != N)
        printf("%d", data[i]);
    else
        printf("None");
    return 0;
}
