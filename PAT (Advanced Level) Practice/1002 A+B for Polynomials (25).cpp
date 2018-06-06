#include <cstdio>

int main(){
    float Polynomial[1001]= {0.0};
    int expon;
    float coef;
    int len;
    scanf("%d", &len);
    while(len--){
        scanf("%d%f", &expon, &coef);
        Polynomial[expon] += coef;
    }
    scanf("%d", &len);
    while(len--){
        scanf("%d%f", &expon, &coef);
        Polynomial[expon] += coef;
    }
    expon = 0;
    for(int i = 0; i <= 1000; i++)
        if(Polynomial[i] != 0.0)
            expon++;
    if(expon == 0){
        printf("0");
        return 0;
    }
    printf("%d", expon);
    for(int i = 1000; i >=0; i--)
        if(Polynomial[i] != 0.0)
            printf(" %d %.1f", i, Polynomial[i]);
    return 0;
}