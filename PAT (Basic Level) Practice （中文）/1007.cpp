#include <cstdio>
#include <cmath>

int main(){
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    if(N%2 == 0) --N;
    int sum = 0;
    int pre = 0;

    for(int i = N; i > 2; i -= 2){
        int flag = 1;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0) flag = 0;
        }

        if(flag){
            if(pre) ++sum;
            pre = 1;
        }
        else pre = 0;
    }
    printf("%d", sum);
    return 0;
}
