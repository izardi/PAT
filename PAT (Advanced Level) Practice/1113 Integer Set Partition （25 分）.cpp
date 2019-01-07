#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    // freopen("data.in", "r", stdin);
    int N, data[1005] = {0};
    scanf("%d", &N);
    int sum = 0;

    for(int i = 0; i < N; ++i){
        scanf("%d", &data[i]);
        sum += data[i];
    }

    sort(data, data + N);
    int halfSum = 0;

    for(int i = 0; i < N / 2; ++i)
        halfSum += data[i];

    printf("%d %d\n", N % 2, sum - 2*halfSum);
    return 0;
}