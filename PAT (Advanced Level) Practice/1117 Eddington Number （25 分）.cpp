#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    // freopen("data.in", "r", stdin);
    int N, data[100005];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &data[i]);
    sort(data, data + N);
    int E = 0;
    for(int i = N-1; i >= 0 && E < N; --i)
        if(data[i] > E + 1) ++E;
    printf("%d\n", E);
    return 0;
}