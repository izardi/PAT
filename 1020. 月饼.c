#include <stdio.h>
struct cake{
    double inventory;
    int price;
    double priceOfTon;
};
int main() {
    int N;
    double D;
    scanf("%d %lf", &N, &D);
    struct cake array[N];
    for (int i = 0; i < N; i++)
        scanf("%lf",&array[i].inventory);
    for (int i = 0; i < N; i++)
        scanf("%d", &array[i].price);
    for (int i = 0; i < N; i++)
        array[i].priceOfTon = (double)array[i].price/array[i].inventory;
    for(int i=0; i< N-1; i++){
        struct cake tmp = array[i];
        for(int j=i+1; j< N; j++){
            if(array[j].priceOfTon > array[i].priceOfTon){
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    int i =0;
    double sum = 0;
    double profit=0;
    while(D > sum ){
        sum += array[i++].inventory;
    }
    if(i == 1){
        profit = array[0].priceOfTon*D;
    }else{
        for (int j = 0; j < i-1; j++) {
            profit += array[j].price;
            D -= array[j].inventory;
        }
        profit += D*array[i-1].priceOfTon;
    }
    printf("%.2f",profit);
    return 0;
}
