#include <cstdio>

int main(){
    const int _MAX = 501;
    int tmp;
    int coins[_MAX] = {0};
    int N, M;
    bool haveSolution = false;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        coins[tmp]++;
    }

    for(int i = 1; i < _MAX; i++){
        if(!coins[i] || (M-i < 0) || (M-i > 500))
            continue;
        if(coins[M-i]){
            if(i == M - i){
                if(coins[i] >= 2){
                    haveSolution = true;
                }
                else continue;
            }
            else haveSolution = true;

            if(haveSolution){
                printf("%d %d", i, M-i);
                break;
            }
        }
    }

    if(!haveSolution)
        printf("No Solution");
    return 0;
}
