#include <cstdio>

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int tmpcolor, color = -1, count = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            scanf("%d", &tmpcolor);
            if( tmpcolor != color){
                if(count == 0)
                    color = tmpcolor;
                else
                    count--;
            }
            else
                count++;
        }

    printf("%d", color);
    return 0;
}
