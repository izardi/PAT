#include <stdio.h>
int main() {
    char A[1001];
    int B;
    int i = 0;
    int tmp =0;
    scanf("%c", &A[i++]);
    while(A[i-1] != ' '){
        scanf("%c", &A[i++]);
    }
    scanf("%d", &B);
    //read end
    if(A[1] ==' '){
        if(A[0]-'0' >= B){
            printf("%d %d", (A[0]-'0')/B, (A[0]-'0')%B);
        }else{
            printf("0 %d", (A[0]-'0')%B);
        }
    }else {
        for (i = 0; A[i] != ' '; i++) {
            if (i == 0) {
                if ((A[i] - '0') > B) {
                    printf("%d", (A[i] - '0') / B);
                    tmp = (A[i] - '0') % B;
                } else {
                    tmp = A[i] - '0';
                }
            } else {
                tmp = tmp * 10 + (A[i] - '0');
                printf("%d", tmp / B);
                tmp = tmp % B;
            }
        }
        printf(" %d", tmp);
    }
    return 0;
}
