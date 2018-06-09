#include <cstdio>
#include <cstring>

void judgeAndOutPut(long long N, long long *A, long long len){
    long long radix = A[0];
    for(int i = 1; i < len; i++)
        if(radix < A[i])
            radix = A[i];
    long long DN = 0;
    radix++;
    long long left = radix;
    long long right = N+1;
    long long mid;
    while(left <= right){
        mid = right - (right-left)/2;
        DN = 0;
        for(int i = 0; i < len; i++)
            DN = DN*mid + A[i];
        if(DN == N){
            printf("%lld", mid);
            return;
        }
        else if(DN >N || DN < 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if(left > right)
        printf("Impossible");
}

int main(){
    long long radix;
    int tag;
    char tmp1[11], tmp2[11];
    scanf("%s %s %d %lld", tmp1, tmp2, &tag, &radix);
    int len1 = strlen(tmp1); 
    int len2 = strlen(tmp2);
    long long N1[11], N2[11];
    for(int i = 0; i < len1; i++)
        N1[i] = tmp1[i] > '9' ? (tmp1[i] - 'a' + 10) : (tmp1[i] - '0');
    for(int i = 0; i < len2; i++)
        N2[i] = tmp2[i] > '9' ? (tmp2[i] - 'a' + 10) : (tmp2[i] - '0');
    
    long long DN = 0;
    if(tag == 1){
        for(int i = 0; i < len1; i++)
            DN = DN*radix + N1[i];
        judgeAndOutPut(DN, N2, len2);
    }
    else{
        for(int i = 0; i < len2; i++)
            DN = DN*radix + N2[i];
        judgeAndOutPut(DN, N1, len1);
    }
    return 0;
}