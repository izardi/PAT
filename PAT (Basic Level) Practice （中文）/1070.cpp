#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    double maxl = arr[0];
    for(int i = 0; i < N; ++i)
        maxl = (maxl+arr[i])/2;
    printf("%d", int(maxl));
    return 0;
}
