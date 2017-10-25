#include <stdio.h>
int main(){
    int A, B, C, D;
    int array[32];
    int i = 0;
    scanf("%d %d %d", &A, &B, &D);
    C = A + B;
    int k;
    if( C > D) {
        do {
            k = C % D;
            array[i++] = k;
            C = C / D;
        } while (C > D);
        array[i] = C;
        for(int k=i; k >=0; k--){
            printf("%d",array[k]);
        }
    }else {
        printf("%d" , C);
    }
    return 0;
}
