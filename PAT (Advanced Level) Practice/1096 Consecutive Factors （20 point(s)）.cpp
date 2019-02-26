#include <cstdio>
#include <cmath>

int main(){
    int N;
    scanf("%d", &N);
    int max = sqrt(N);
    for(int len = 12; len >= 1; --len){
        for(int start = 2; start <= max; ++start){
            long long int tmp = 1;
            for(int i = start; i - start + 1 <= len; ++i)
                tmp *= i;
            if(N % tmp == 0){
                printf("%d\n%d", len, start);
                for(int i = start+1; i-start+1 <= len; ++i)
                    printf("*%d", i);
                return 0;
            }
        }
    }
    printf("1\n%d", N);
    return 0;
}
