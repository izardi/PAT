#include <cstdio>

const int up = 6;
const int down = 4;
const int stop = 5;

int main(){
    int N;
    scanf("%d", &N);
    int sum = N*stop;
    int i =0;
    int tmp;
    while(N--){
        scanf("%d", &tmp);
        if(i < tmp)
            while(i < tmp){
                sum += up;
                i++;
            }
        else if(i > tmp)
            while( i > tmp){
                sum += down;
                i--;
            }
    }
    printf("%d", sum);
    return 0;
}