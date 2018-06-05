#include <cstdio>
#define MAXLEN 20

int main(){
    int a, b;
    int array[MAXLEN];
    int cnt = 0;
    scanf("%d %d", &a, &b);
    long long sum = a + b;
    if(sum < 0){
        printf("-");
        sum = sum * -1;
    }
    else if(sum == 0){
        printf("0");
        return 0;
    }
    while( sum > 0){
        array[cnt++] = sum % 10;
        sum /= 10;
    }
    for(int i = cnt -1; i >= 0; i--){
        printf("%d", array[i]);
        if(!(i%3) && i != 0)
            printf(",");
    }
    return 0;
}