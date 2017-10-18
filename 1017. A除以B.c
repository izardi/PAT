#include <stdio.h>
int main(){
    int A[1001], B;
    int C[1001];
    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != ' '){
        A[i++] = c - '0';
        scanf("%c", &c);
    }
    //array length = i-1
    scanf("%d", &B);
    if(B != 1){
        int tmp, k=1;
        if (A[0]/B > 0){
            C[k-1] = A[0]/B;
            tmp = A[0]%B;
            for(k=1; k<i; k++){
                tmp = tmp*10 + A[k];
                C[k-1] = tmp/B;
                tmp = tmp%B;
            }
        }else {
            tmp = (A[k-1]*10+A[k]);
            C[k-1] = tmp/B;
            tmp = tmp % B;
            for(k=2; k<i; k++){
                tmp = tmp*10 + A[k];
                C[k-1] = tmp/B;
                tmp = tmp%B;
            }
        }
        for(int j=0; j<k-1; j++){
            printf("%d",C[j]);
        }
        printf(" ");
        printf("%d", tmp);
    }
    else {
        for(int j = 0; j < i; j++)
            printf("%d", A[j]);
        printf(" 0");
    }
    return 0;
}
