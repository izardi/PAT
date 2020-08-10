#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    int K;
    scanf("%d", &K);
    int tmp;
    int arr[101] = {0};
    for(int i = 0; i < K; ++i){
        scanf("%d", &tmp); 
        arr[tmp] = 1;
    }
    for(int i = 2; i <= 100; ++i){
        if(arr[i]){
            int k = i;
            while(k != 1){
                if(k%2)
                    k = (3*k+1)/2;
                else
                    k /= 2;
                if(k > 1 && k <= 100)
                    arr[k] = 0;
            }
        }
    } 
    int flag = 0;
    for(int i = 100; i > 1; --i)
        if(arr[i]){
            if(flag) printf(" ");
            flag = 1;
            printf("%d", i);
        }
    return 0;
}
//n 偶数/2 奇数(3n+1)/2 重复最后n=1
