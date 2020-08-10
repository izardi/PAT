#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    long long p;
    scanf("%d %lld", &N, &p);
    int arr[100005];
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    
    int maxlen = 0;
    int i, j;
    for(i = 0; i < N && maxlen < N - i; ++i){
        for(j = i + maxlen; j < N; ++j)
            if(arr[i]*p < arr[j])
                break;
        if(j - i > maxlen)
            maxlen = j-i;
    }
    printf("%d", maxlen);
    return 0;
}
