#include <cstdio>
#include <algorithm>
using namespace std;
int N, fir[105], sec[105];

int main(){
    // freopen("data.in", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &fir[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &sec[i]);
    int i, j;
    for(i = 0; i < N - 1 && sec[i] <= sec[i+1]; ++i);
    for(j = i + 1; j < N && fir[j] == sec[j]; ++j);
    if(j == N){
        printf("Insertion Sort\n");
        sort(fir, fir+i+2);
    }else{
        printf("Merge Sort\n");
        int k = 2;
        while(true){
            int flag = 0;
            for(i = 0; i < N; ++i)
                if(fir[i] != sec[i]){
                    flag = 1;
                    break;
                }
            for(i = 0; i < N/k; ++i)
                sort(fir + i*k, fir + (i+1)*k);
            sort(fir + N/k*k, fir + N);
            if(flag == 0) break;
            k *= 2;
        }
    }
    printf("%d", fir[0]);
    for(int i = 1; i < N; ++i)
        printf(" %d", fir[i]);
    return 0;
}
