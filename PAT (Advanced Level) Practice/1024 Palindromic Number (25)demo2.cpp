#include <cstdio>

bool isPalindromic(const int * A, int len){
    int i = 0;
    for(; i < len/2; i++)
        if(A[i] != A[len-1-i])
            break;
    return (i == len/2);
}
void printArray(const int * A, int len){
    for(int i = len-1; i >= 0; i--)
        printf("%d",A[i]);
    printf("\n");
}
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int ON[10000], RN[10000];
    int cnt = 0;
    do{
        ON[cnt++] = N % 10;
        N /= 10;
    }while( N > 0);
    for(int i = 0; i < cnt; i++)
        RN[i] = ON[cnt-i-1];
    int steps = 0;
    int carry, tmp;
    while(steps < K && !isPalindromic(ON, cnt)){
        carry = 0;
        for(int i = 0; i < cnt; i++){
            tmp = ON[i] + RN[i] + carry;
            ON[i] = tmp % 10;
            carry = tmp / 10;
        }
        if(carry)
            ON[cnt++] = carry;
        for(int i = 0; i < cnt; i++)
            RN[i] = ON[cnt-i-1];
        steps++;
    }

    printArray(ON, cnt);
    printf("%d\n", steps);
    return 0;
}