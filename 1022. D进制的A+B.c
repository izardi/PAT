#include <stdio.h>
int main(){
    int A, B, C, D;
    int array[31];
    int i = 0;
    scanf("%d %d %d", &A, &B, &D);
    C = A + B;
    if(C != 0 ) {
        while (C != 0) {
            array[i++] = C % D;
            C /= D;
        }
        for (int k = i - 1; k >= 0; k--)
            printf("%d", array[k]);
    }else
        printf("0");
    return 0;
}
