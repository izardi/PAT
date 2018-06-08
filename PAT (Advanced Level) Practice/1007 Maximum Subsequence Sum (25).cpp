#include <cstdio>

int main(){
    
    int K, num_s = 0, num_e = 0, sum = 0, maxSum = -1, tmp;
    int tmp_s = 0;
    int first, last;
    scanf("%d", &K);
    bool isStar = 1;
    for(int i = 0; i < K; i++){
        
        scanf("%d", &tmp);
        sum += tmp;
        
        if(isStar){
            tmp_s = tmp;
            isStar = 0;
        }
        
        if(maxSum < sum){
            num_s = tmp_s;
            maxSum  = sum;
            num_e = tmp;
        }
        if(sum < 0){
            sum = 0;
            isStar = 1;
        }
        
        if(i == 0) first = tmp;
        if(i == K-1) last = tmp;
    }
    if(maxSum >= 0)
        printf("%d %d %d", maxSum, num_s, num_e);
    else
        printf("0 %d %d", first, last);
    return 0;
}