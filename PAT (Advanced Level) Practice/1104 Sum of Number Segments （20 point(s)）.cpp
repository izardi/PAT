#include <cstdio>

int main(){
    int N;
    scanf("%d", &N);
    double sum = 0, array[100005];
    for(int i = 1; i <= N; ++i){
        scanf("%lf", &array[i]);
        sum += array[i]*i*(N-i+1);
    }
    printf("%.2lf\n", sum);
    return 0;
}
